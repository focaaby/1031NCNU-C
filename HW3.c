/*
* File Name: 100213020_HW3.c
* ID:100213020
* Author: Maolin Wang
* Since 2014/10/15
* Toolkit: vim 
*/

#include <stdio.h>
int isLeap(int y) {
    return y%400 ==0 || (y%4 == 0 && y%100 != 0); // 判斷閏年
} 
int main() {
    int year;     
    char type;
    scanf("%d%c", &year,&type);
    type=='a'?(isLeap(year)>0?printf("YES\n"):printf("NO\n")):(isLeap(year+1911)>0?printf("YES\n"):printf("NO\n")); //如果是西元進入函數判斷是否閏年, 其他則是民國進入函數判斷是否閏年
}
