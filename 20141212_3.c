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

int main(int argc, char *argv[]) {
    int i, len;
    char buf[1000];
    FILE *f;
    if (argc == 2) {
        f =fopen(argv[1], "r"); //open with read only mod 
        if ( f == NULL) {
            printf("file open fail, please check filename and privilege\n");
            return 1;
        }   
        while (fscanf(f, "%s", buf) != EOF) {
            printf("%s\n", buf);
        }
    } else {
        printf("please specify filename as the first argument\n");
    }
    return 0;
}
