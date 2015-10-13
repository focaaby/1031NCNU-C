#include <stdio.h>
void insertSort(char s[], int n) {
    // how to implement insertion sort?
    int i, j;
    char tmp;
    for (i = 1; i < n; i++) { // i表示要插入的元素
        tmp = s[i];
        // 以下迴圈找出要插入的位置
        // j是要比較的位置,由i-1往左邊比到0為止,或是s[j]<=tmp
        for (j = i - 1; j >= 0 && s[j] > tmp; j--) {
             s[j+1] = s[j];
        }
        // j+1才是要放入的位置
        s[j+1] = tmp;
    }
}
// in C, String is represented by array of char terminated with 0
int strlen(char s[]) {
    int r;
    // 找出字串的長度
    for (r = 0; s[r] != 0; r = r + 1)
        ;
    return r;
}
// s 表示要排列的資料
// n 表示此陣列的大小
// m 表示要選出的數量
// pos 表示要排列pos ~ n-1之間選出m-got個資料
// got 表示已經選好的個數
void combi(char *s, int n, int m, int pos, int got) {
    int i;
    // 請問終止條件
    if (m == got) {
        // 印出來看對不對
        for (i = 0; i < m; i++) 
            printf("%c", s[i]);
        printf("\n");
        return;
    }
    //如何化簡？
    //由pos道n-1間可以任選出i位置的元素
    for (i = i; i <= n-1; i++) {
        //如何選定？選定到哪個位置？
        //應該選到 got 這個位置上！
        //若採用 swap(got,i) 的方式選擇, 那程式應該這樣寫
        tmp = s[i];
        s[i] = s[got];
        s[got] = tmp;
        //接下來如何recursion?
        //由 i+1 開始選, 因為組合和位置無關, 前面選過的組合不能再選
        /* Example
           A B C D E  c(5, 2)
           A -> AB, AC, AD, AE
           B -> BC ,BD, BE
           C -> CD, CE
           E -> DE
        */
        combi(s, n, m, i+1 , got+1);
        //recursion 完要記得還原陣列
        tmp = s[i];
        s[i] = s[got];
        s[got] = tmp;
    }
}

void perm(char *s, int n, int pos) {
    int i, j;
    char tmp;
    // recursion 的第一行一定是終止條件
    if (pos >= n - 1) {
        // 為確定我們做對了,把資料印出來
        printf("%s\n", s);
        return;
    }
    // 開始化簡
    // 目標是把pos ~ n-1間的元素都逐一嘗試固定到pos這個位置上
    // 然後recursion 
    for (i = pos; i < n; i++) {
        // 選定i位置的元素到pos位置上
        // 方法之一是透過swap(i, pos)
        // 方法二是insert
        //  此法比較慢,但可以保持原先輸入的順序
        // 先把s[i]複製到tmp, 這樣就空出i位置
        tmp = s[i];
        // 把i-1 ~ pos間的元素都往右移動
        for (j = i - 1; j >= pos; j--)
            s[j+1] = s[j];
        // 再把原先s[i]的值放的pos上
        s[pos] = tmp;
        // 既然已經選定, 可以recursion了
        perm(s, n, pos+1);
        // 因為上面的insert動過陣列,為使程式正確執行
        // 我們再做一次"反向" insert, 來復原資料
        // 反向的話,把s[pos]複製到tmp,這樣就空出最左邊的位置
        tmp = s[pos];
        // 把pos +1 ~ i間的元素都往左移動
        for (j = pos + 1; j <= i; j++)
            s[j-1] = s[j];
        // 再把原先s[pos]的值放到i上 
        s[i] = tmp;
    }
}
int main() {
    char s[128];
    int m;
    scanf("%s", s, &m);
    return 0;
}
