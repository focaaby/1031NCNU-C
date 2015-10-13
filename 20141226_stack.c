#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// link list 做 stack
/*
  
stack sample:
       ____     ___     ___
      |head|-> |___| ->|___| -> .... 
      |____|    
      |size|
      |____|

---------------------------------------
-------------<PROBLEM QAQ>-------------
** delete node 
=> memory leakage in C 
=> use "free" to free memory


*/
struct node {
    char *data;
    struct node *next;
};

struct stack {
    int size; //how many elements curently in the stack
    struct node *head;
};

void initStack(struct stack *s) {
    s->head = NULL;
    s->size = 0;
}

void addStack(struct stack *s, char *val) {
    struct node *tmp = (struct node*)malloc(sizeof(struct node)); //memory allocation 
    tmp->data = (char*)malloc(strlen(val)+1);
    strcpy(tmp->data, val);
    tmp->next = s->head;
    s->head = tmp;
    s->size++;
}

char * deleteStack(struct stack *s){
    struct node *tmp;
    char *rel;
    tmp = s->head;
    s->head = s->head->next;
    s->size--;
    rel = tmp->data;
    free(tmp);
    return tmp->data;
}

int emptyStack(struct stack *s) {
   // return s->head == NULL;
    return s->head == 0;
}

void printStack(struct stack *s) {
    struct node *tmp;
    for (tmp = s->head; tmp!=NULL; tmp = tmp->next)
        printf("%s\n", tmp->data);
}



int main(int argc, char *argv[]) {
    int i, len;
    char buf[1000];
    FILE *f;
    struct stack s;
    char *tmp;
    initStack(&s);
    if (argc == 2) {
        f =fopen(argv[1], "r"); //open with read only mod 
        if ( f == NULL) {
            printf("file open fail, please check filename and privilege\n");
            return 1;
        }   
        while (fscanf(f, "%s", buf) != EOF) {
            addStack(&s, buf);
        }
        while(!emptyStack(&s)) {
            printf("%s\n", tmp=deleteStack(&s));
            free(tmp); //用完再釋出記憶體空間
        }
    } else {
        printf("please specify filename as the first argument\n");
    }
    return 0;
}
