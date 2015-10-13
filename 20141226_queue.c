#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// link list 做 queue
/*
  
queue sample:                          
                                       last one
       ____     ___     ___               ___
      |head|-> |___| ->|___| -> .... ->  |___|
      |____|                               ^
      |tail|                               |
      |____| ------------------------------
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

struct queue {
    int size;
    struct node *head;
    struct node *tail;
};

void initQueue(struct queue *q) {
    q->head = q->tail = NULL;
    q->size = 0;
}

void addQueue(struct queue *q, char *val) {
    struct node *tmp = (struct node*)malloc(sizeof(struct node)); //memory allocation 
    tmp->data = (char*)malloc(strlen(val)+1);
    strcpy(tmp->data, val);
    tmp->next = NULL;
    if (q->tail != NULL) {
        q->tail->next = tmp;
    } else {
        q->head = tmp;
    }
    q->tail = tmp;
    q->size++;
}
/*
char * deleteQueue(struct queue *q){
    struct node *tmp = q->head;
    q->head = tmp->next;
    if (q->head == NULL) {
        q->tail = NULL;
    }
    free(tmp->data);
    free(tmp);
    return tmp->data;
}
*/
char * deleteQueue1(struct queue *q){
    struct node *tmp = q->head;
    char * data;
    q->head = tmp->next;
    if (q->head == NULL) {
        q->tail = NULL;
    }
    data = tmp->data;
    
    printf("\n");
    printf("data: %p, %p\n", &data, data);
    printf("tmp: %p, %p\n", &tmp, tmp);
    printf("tmp->data: %p, %p\n", &tmp, tmp->data);
    
    free(tmp);
    printf("AFTER FREE tmp\n");
    printf("data: %p, %p\n", &data, data);
    printf("tmp: %p, %p\n", &tmp, tmp);
    printf("tmp->data: %p, %p\n", &tmp, tmp->data);
   
    free(data);
    printf("AFTER FREE data\n");
    printf("data: %p, %p\n", &data, data);
    printf("tmp: %p, %p\n", &tmp, tmp);
    printf("tmp->data: %p, %p\n", &tmp, tmp->data);
    printf("\n");
    
    return data;
}

int emptyQueue(struct queue *q) {
    return q->head == NULL;
}

int main(int argc, char *argv[]) {
    int i, len;
    char buf[1000];
    FILE *f;
    struct queue q;
    char *tmp;
    initQueue(&q);
    if (argc == 2) {
        f =fopen(argv[1], "r"); //open with read only mod 
        if ( f == NULL) {
            printf("file open fail, please check filename and privilege\n");
            return 1;
        }   
        while (fscanf(f, "%s", buf) != EOF) {
            addQueue(&q, buf);
        }
        while(!emptyQueue(&q)) {
            printf("%s\n", tmp = deleteQueue1(&q));
        }
    } else {
        printf("please specify filename as the first argument\n");
    }
    return 0;
}
