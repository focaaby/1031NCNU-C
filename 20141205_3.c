#include <stdio.h>
#include <stdlib.h>
//struct是C語言用來"自訂"資料型態的語法
struct node {
    int data;
    struct node *next;
};

//linked list is a data structure like
// --> N --> N -->
// all data(node) were chinaed together
//insert value to the beginning if linked list

void insert(struct node ** head, int d) {
    struct node *tmp;
    // malloc is a fuction which allocates n bytes and retrun a pointer to the memory 
    tmp = malloc(sizeof(struct node));
    //pointer to structure時, 可以運用->符號來存取struct內的成員,此語法等同
    // (*tmp).data = data
    tmp->data = d;
    tmp->next = *head;
    *head = tmp;
}
//define is a "macro", that means "string replacement" before compile
//#define NULL 0
int main() {
    struct node *head, *tmp;
    int val, i , n;
    //NULL has been defined in stdio.h
    head = NULL;
    //the above statement is tha same as 
    // head = 0;
    //讀入n, 在讀入n整數, 將這些整數放到lined list 所建構出的stack內
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        insert(&head, val);
    }
    //印出的順序
    for (tmp = head; tmp != NULL; tmp = tmp ->next) {
        printf("%d\n", tmp->data);
    }   
    return 0;
}
