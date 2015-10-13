#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {   // 
    int studentID; 
    char *name;
    struct node *next;
};

struct hashtable {
    int buckets;
    struct node **table;
};

void initHash(struct hashtable *h, int size) {
    int i;
    h->buckets = size;
    h->table = (struct node **)malloc(size*sizeof(struct node*));
    for (i = 0; i <size; i++) {
        h->table[i] = NULL;
    }
}

unsigned hashCode(char *s) {
    int i;
    unsigned rel = 0;
    while (*s != 0) {
        rel = rel * 4 +(unsigned)*s;  //4 位移2 bits
        s++;
    }
    return rel;
}

void addHash(struct hashtable *h, int num, char *buf) { //將buf改成多一個參數, buf1暫存number, buf2暫存name
    struct node *tmp = (struct node*)malloc(sizeof(struct node)); //memory allocation 
    tmp->studentID = (int)malloc(sizeof(int)); 
    tmp->name = (char*)malloc(strlen(buf)+1);
    tmp->studentID = num;
    strcpy(tmp->name, buf);
    int b = hashCode(num) % h ->buckets;
    tmp->next = h->table[b];
    // add to the a head of this bucket
    h->table[b] = tmp;
}

//檢查buf是否存在於hashtable內
struct node * existHash(struct hashtable *h, int num) { //把return int改為return pointer to node的型態(回傳node位置)
    int b = hashCode(num) %h->buckets;
    struct node *tmp;
    for (tmp = h->table[b]; tmp != NULL; tmp = tmp->next) {
        if (tmp->studentID == num)
            return tmp;  //改成return 被檢查到的節點位置
    }
    return 0;
}

int main(int argc, char *argv[]) {
    int i, len;
   // char buf1[1000];
    int inputID;
    char buf[1000];  //多宣告一個buf2暫存字串, buf2儲存name
    FILE *f;
    struct hashtable h;
    struct node *check; 
    initHash(&h, 13);
    if (argc >= 2) { 
        f =fopen(argv[1], "r"); //open with read only mod 
        if ( f == NULL) {
            printf("file open fail, please check filename and privilege\n");
            return 1;
        }   
        while (fscanf(f, "%d %s", inputID, buf) != EOF) {  //改成兩個input, 以空格間隔
            addHash(&h, inputID, buf);
        }
    } else {
        printf("please specify filename as the first argument\n");
    }
    // test hash table
    printf("Please input your studentID:");
    scanf("%d", &inputID);
    check = existHash(&h, &inputID); //檢查時, 用學號檢查
    if (check != NULL ) {
        printf("Your student name is %s\n", check->name);
    } else {
        printf("You student ID is not exist!!\n");
    }
    return 0;
}
