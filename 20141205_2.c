#include <stdio.h>

//struct是C語言用來"自訂"資料型態的語法
struct student {
    int id;
    int age;
};
// typedef 是C語言用來"縮短"型態名稱的語法
// 經過下面定義, cimpiler 看到STUDENT就會自動翻譯成struct student
typedef struct student STUDENT

int main() {
    //C語言如何開檔讀資料？
    
    return 0;
}



/* Part 2
int main() {
    struct student x[20];
    STUDENT y;
    // 以上等同 struct student y;
    int i;
    for (i = 1;i <= 20; i++) {
         x[i-1].id = i;
         x[i-1].age = 18;
    }
    for (i = 0; i < 20; i++)
        printf("id si %d, age is %d\n", x[i].id, x[i].age); 
    retrun 0;
}
*/

/* Part 1 
int main() {
   struct student x;
   x.id = 5;
   x.age = 18;
   printf("id is %d, age is %d\n", x.id , x.age);
   retrun 0;
}
*/
