#include <stdio.h>

// return 0 == not a prime
// return num  == a prime

// 檢查num是否整除
// 整除 -> num不是prime

int prime(int num){
    int i;
    for (i = 2; i < num; i++) {
        if(num % i == 0)
            return 0;
    }
    return num;
}

int main(){
//input a num check for 質數 1~a
    int i,n;
    scanf("%d", &n);
    for(i = 2; i <= n; i++){
        if(prime(i) > 0)
           printf("%d ", i);
    }
    printf("\n");
    return 0;
}
