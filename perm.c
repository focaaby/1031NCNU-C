/*
輸入一個字元陣列，列出所有字元排列
如輸入 ABC
輸出
ABC
ACB
BAC
BCA
CBA
CAB
*/
#include <stdio.h>

// 找出字串長度
int mystrlen(char s[]) {
    int r;
    for(r = 0; s[r] != 0; r++)
        ;
    return r;
}
// s 表示要排列的資料
// n 表示陣列的大小
// pos 表示要排列 pos~n-1 之間的資料
void perm(char *s, int n, int pos) {
    int i, tmp;
    // recursion 的第一行一定是終止條件
    if(pos >= n-1) {
        // 為確定我們做對了，把資料印出來
        printf("%s\n", s);
        return;
    }
    // 開始化簡
    // 目標是把 pos~n-1 間的元素逐一長是固定到 pos 這個位置上
    // 然後 recursion

    for(i = pos; i < n; i++) {
        // 選定位置的元素到 pos 位置上
        // 方法之一是透過 swap(i, pos)
        tmp = s[pos];
        s[pos] = s[i];
        s[i] = tmp;
        // 選定後，recursion
        perm(s, n, pos+1);
        // 因為上面的 swap 透過陣列，為使程式正確執行
        // 我們再做一次 swap 當「反運算」，來復原資料
        tmp = s[pos];
        s[pos] = s[i];
        s[i] = tmp;
    }
}

int main() {
    char s[128];
    scanf("%s", s);
    perm(s, mystrlen(s), 0);
    return 0;
}
