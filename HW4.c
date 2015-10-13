#include <stdio.h>
int reverse(int x) {
    int y = 0;           //x是要反轉的數字, y是反轉的結果
    while(x != 0) {        //當數字為0時, 表示沒有數字在其中 
        y = y * 10 + x % 10;  // 當x內還有數字時, 取出x的最後一個數字, 再把此數字放到y後面
        x /= 10;               // 把x的最後一個數字拿走
    }
    return y;
}
int main() {
    int num;
    scanf("%d",&num);
    printf("%d\n",reverse(num));
    return 0;
}
