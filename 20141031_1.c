#include <stdio.h>
/*
**recursion 遞迴
**如果一個function會呼叫自己, 則稱為recusion
**把此加總程序包成一個函數

1. 定義參數的個數和意義
2. 用if表達"中止"條件
3. 用recursion化簡問題(90% 的狀況有迴圈)
*/

int sumation (int n) {
   int i, sum;
   for (sum = 0, i = 1; i<= n; i = i +1) {
       sum = sum + i;
   }
   return sum;
}
//
int power(int x, int n) {
    int sum = 1, i;
    for(i =1; i < n;i = i +1 ) {
        sum = sum * x;
    }
    return sum;
}

int pow(int x, int n) {
    if (n == 0) {
        return 1;
    }
    // 化簡
    return x * pow(x,n); 
}


int sum(int n) {
    if (n <= 1) {
        return n;
    }
}

int f(int n) {
    if (n <= 1) {
        return n;
    }
    return f(n-1)+f(n-2);
}

int main() {
    int x, sum, n;
    scanf("%d %d", &x, &n);
    printf("%d\n", pow(x,n));  
    return 0;
}
