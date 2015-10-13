#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct stack {
    struct node *head;
    int size;
};
struct queue {
    struct node *head, *tail;
    int size;
};
struct hashNode {
    int key;
    int val;
    struct hashNode *next;
};
struct hash {
    struct hashNode **b;
    int size;
};
void initHash(struct hash *h, int n) {
    int i;
    h->b = (struct hashNode **)malloc(n*sizeof(struct hashNode*));
    h->size = n;
    for (i = 0; i < n; i++)
        *(h->b+i) = NULL;
}
void addHash(struct hash *h, int k, int v) {
    int f = k%h->size;
    struct hashNode *tmp = (struct hashNode*)malloc(sizeof(struct hashNode));
    tmp->next = h->b[f];
    tmp->key = k;
    tmp->val = v;
    h->b[f] = tmp;
}
int exist(struct hash *h, int k) {
    int f = k%h->size;
    struct hashNode *head = h->b[f];
    while (head != NULL) {
        if (head->key == k)
            return 1;
        head = head->next;
    }
    return 0;
}
void initQueue(struct queue *q) {
    q->head = q->tail = NULL;
    q->size = 0;
}
void addQueue(struct queue *q, int d) {
    struct node *tmp = (struct node*)malloc(sizeof(struct node));
    tmp->data = d;
    tmp->next = NULL;
    if (q->tail != NULL) {
        q->tail->next = tmp;
    } else {
        q->head = tmp;
    }
    q->tail = tmp;
    q->size++;
}
int deleteQueue(struct queue *q) {
    struct node *tmp = q->head;
    q->head = q->head->next;
    if (q->head == NULL)
        q->tail = NULL;
    free(tmp);
    q->size--;
    return tmp->data;
}
int isemptyQueue(struct queue *q) {
    return q->head == NULL;
}
void initStack(struct stack *s) {
    s->head = NULL;
    s->size = 0;
}
void pushStack(struct stack *s, int d) {
    struct node *tmp = (struct node*)malloc(sizeof(struct node));
    tmp->next = s->head;
    s->head = tmp;
    tmp->data = d;
    s->size++;
}
int popStack(struct stack *s) {
    struct node *tmp = s->head;
    int d = tmp->data;
    s->head = s->head->next;
    free(tmp);
    s->size--;
    return d;
}
int isemptyStack(struct stack *s) {
    return s->head == NULL;
}
int main() {
    int i;
    struct hash h;
    initHash(&h, 13);
    for (i = 1; i <= 10; i++)
        addHash(&h, i, i);
    if (exist(&h, 9))
        printf("found\n");
    else
        printf("not found\n");
    return 0;
}
