// zadanie1.c -- Jakub Müller, 7.10.2019 10:27

#include <stdio.h>
#include <string.h>

#define BLOCK_SIZE sizeof(mem_block)

typedef struct mem_block {
    unsigned int size;
    struct mem_block *next;
}mem_block;

mem_block *head;

//funkcia, ktora upravuje velkost bloku na parne cislo
int align(size_t n){
    while(n % 2 != 0){
        n++;
    }
    return n; //vrati pocet bytov potrebnych na alokaciu
}

//funkcia, ktora odstrani danu node zo spajaneho zoznamu
void remove_node(mem_block *node){

    mem_block *temp = head->next,
            *curr = head->next,
            *ptr;

    if(node == head->next){
        head->next = temp->next;
    }
    else{
        while(curr){
            if(curr->next == node){
                ptr = curr;
                ptr = ptr->next;
                curr->next = ptr->next;
            }
            curr = curr->next;
        }
    }
}

//ak sa blok da rozdelit tak ho rozdeli na dva
//tato funkcia vracia smernik na node, ktora pojde uzivatelovi
mem_block *block_split(mem_block *block, unsigned int size){
    mem_block *temp = block;
    int space = 0;
    char *c = temp;

    //zistujem, kam mam nasmerovat smernik na novu node
    //ak je pozadovana velkost mensia ako velkost struktury - sizeof(int)
    //tak blok bude mat velkost struktury - sizeof(int), cize 12
    if((int)(size - (BLOCK_SIZE - sizeof(int))) <= 0){
        c += BLOCK_SIZE;
        space = BLOCK_SIZE;
        size = BLOCK_SIZE - sizeof(int);
    }
    else{
        c += BLOCK_SIZE + (size - sizeof(head) - sizeof(int));
        space = BLOCK_SIZE + (size - sizeof(head) - sizeof(int));
    }

    temp  = c;

    if(block->next == NULL){
        block->next = temp;
        temp->next = NULL;
        temp->size = block->size - space;
        block->size = size;
    }

    return block;
}

//funkcia na hladanie volneho bloku pamate,
//ktory vyhovuje uzivatelovi velkostou
//vrati smernik na vhodny blok, alebo NULL, ak nic nenajde
mem_block *find_block(unsigned int size){
    mem_block *block = head->next;

    while(block){
        if(block->size < size){
            block = block->next;
            continue;
        }
        if(block->size < size && memory_check(block) == 1)
            return 0;

        mem_block *p = head->next;
        while(p){
            printf("%d ->", p->size);
            p = p->next;
        }
        printf("\n");
        //
        if((block->size - size) >= BLOCK_SIZE){
            block = block_split(block, size);
        }
        mem_block *t = head->next;
        while(t){
            printf("%d ->", t->size);
            t = t->next;
        }
        printf("\n");

        remove_node(block);
        mem_block *a = head->next;
        while(a){
            printf("%d ->", a->size);
            a = a->next;
        }
        printf("\n");

        return block;
    }
    return NULL;
}

void *memory_alloc(unsigned int size){
    if(size <= 0)
        return NULL;

    size = align(size);

    mem_block *block;

    if((block = find_block(size))){
        block->size += 1;
        return ((void *)block + sizeof(int));
    }
    printf("nemozno alokobvat!\n");
    return 0;
}


int memory_free(void *valid_ptr){
    if(memory_check(valid_ptr) == 0){
        return 0;
    }

    mem_block *block = valid_ptr - sizeof(int);

    mem_block *temp = head->next, *ptr = head->next;

    block->size -= 1;

    if(head->next == NULL){
        head->next = block;
        block->next = NULL;
        return 1;
    }

    while(temp->next && (block->size >= temp->size)){
        temp = temp->next;
    }
    if(temp == head->next && (block->size <= temp->size)){
        block->next = ptr;
        head->next = block;
        return 1;
    }
    else{
        if(temp->next == NULL && (temp->size < block->size)){
            temp->next = block;
            block->next = NULL;
            return 1;
        }

        while(ptr){
            if(ptr->next == temp){
                ptr->next = block;
                break;
            }
            else if(ptr == temp){
                ptr->next = block;
                block->next = NULL;
                return 1;
            }
            ptr = ptr->next;
        }

        block->next = temp;
    }
    return 0;
}

int memory_check(void *ptr){
    int *size = (void*)ptr - sizeof(int);
    if(*size%2 == 1)
        return 1;
    return 0;
}

void memory_init(void *ptr, unsigned int size){
    head = ptr;
    head->size = size;

    mem_block *block = head + 1;
    head->next = block;
    block->size = head->size - BLOCK_SIZE - sizeof(int);
    block->next = NULL;

    printf("%p\n", head);
    mem_block *p = head->next;
    while(p){
        printf("%d ->", p->size);
        p = p->next;
    }
    printf("\n");

    return;
}

// Vlastna funkcia main() je pre vase osobne testovanie. Dolezite: pri testovacich scenaroch sa nebude spustat!
int main()
{
    char region[100];
    memory_init(region, 100);
    printf("malloc(a)\n");
    char *a = memory_alloc(8);
    printf("a === %p\n", a);

    printf("malloc(b)\n");
    char *b = memory_alloc(8);
    printf("b === %p\n", b);

    printf("malloc(c)\n");
    char *c = memory_alloc(8);
    printf("c === %p\n", c);

    printf("malloc(d)\n");
    char *d = memory_alloc(8);
    printf("d === %p\n", d);

    printf("malloc(e)\n");
    char *e = memory_alloc(8);
    printf("e === %p\n", e);

    printf("malloc(f)\n");
    char *f = memory_alloc(8);

    printf("freeing b\n");
    memory_free(b);
    printf("b === %p\n", b);
    printf("xxxxxx    %p\n", head->next);
    printf("--------------\n");
    mem_block *p = head->next;
    while(p){
        printf("%d ->", p->size);
        p = p->next;
    }
    printf("\n");
    memory_free(a);
    mem_block *x = head->next;
    while(x){
        printf("%d ->", x->size);
        x = x->next;
    }
    printf("\n");
    memory_free(d);

    mem_block *g = head->next;
    while(g){
        printf("%d ->", g->size);
        g = g->next;
    }
    printf("\n");
    return 0;
}