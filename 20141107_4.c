#include <stdio.h>
/*
## pointer is a data type like int, float, char etc.
## operators for pointer are &, *, +, -
##
##  C 參數傳值只有 call by value 
##  把"運算式"的值"複製"一份到stack
##
*/
int sum(int x) {
    if (x == 0)
        return 0;
    return x + sum(x-1);
}

int main() {
    int x = 100;
    int *y;
    y = &x;
    /*
   ##	 y is a pointer to int
   ##	 that is y stories "address" if variable which stores int
   ##	 y points to x
   ##	 y  => 取y的內容
   ##	*y  => 透過y所儲存的地址去抓另一個
   ##
	  |________|
	x |   100  |<--   0028FF1c
	  |________|   |
	y |0028FF1C|---   0028Fc20
	  |
	  |

 
    */
    printf("x 的內容是 %d\n", x);
    printf("x 地址是 %p\n", &x);
    printf("y 的內容是 %p\n", y);
    printf("y 地址是 %p\n", &y);
    printf("*y is %d\n", *y);
    return 0;
}
