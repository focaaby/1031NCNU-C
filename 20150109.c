#include <stdio.h>
#include <stdlib.h>

struct queen {
    int n; // n皇后問題
    int dir[3]; //左下, 正下, 右下, 三個方向的offset
    char *board; //盤面狀態
    int solutions; // 找到幾組解答
};

void initQueen(struct queen *q, int n) {
    int i, j;
    q->n = n;
    q->dir[0] = n + 1;
    q->dir[1] = n + 2;
    q->dir[2] = n + 3;
    q->board = (char*)malloc((n+2)*(n+2)*sizeof(char));
    q->solutions = 0;
    //想辦法中間設為0, 四周設為-1
    for (i = 0; i < n + 2;i++) {
        q->board[i] = -1; //上面
        q->board[(n+1)*(n+2)+i] = -1; //下面
        q->board[i*(n+2)] = -1; //左邊
        q->board[i*(n+2)+n+1] = -1; //右邊
    }
    //處理中間的0
    for (i = 1; i<=n ;i++) {
        for (j =1; j <= n;j++) {
            q->board[i*(n+2)+j] = 0;
        }
    }
}

void putQueen(struct queen *q, int row) {
    int i, j, pos;
    if (row > q->n) { //已經放n上皇后了
        q->solutions++;
        for (i = 1; i <= q->n; i++) {
            for (j = 1; j <= q->n; j++) {
	        if (q->board[i*(q->n+2)+j] == 'Q')
	            printf("后");
	        else
	            printf("口");
            } 
            printf("\n");
        }
        printf("\n");
        return;
    }
    //開始畫減, 再row列放上皇后
    for (i = 1; i <= q->n; i++) {
        //若此位置沒有其他皇后吃得到
        if(q->board[row*(q->n+2)+i] == 0) {
            //放上皇后
            q->board[row*(q->n+2)+i] = 'Q';
            //設定下方勢力範圍, 共有3個方向要設定
            for (j = 0; j < 3; j++) {
                for (pos = row*(q->n+2)+i+q->dir[j]; q->board[pos] >= 0; pos += q->dir[j]) {
                    q->board[pos]++;
                }
            }
            //開始recusion放下一個皇后
            putQueen(q, row+1);
            //回復原來的狀態
            //移除皇后
            q->board[row*(q->n+2)+i] = 0;
            //反射訂下方式一範圍共有三個方向要設定
            for (j = 0; j < 3; j++) {
                for (pos = row*(q->n+2)+i+q->dir[j]; q->board[pos] >= 0; pos += q->dir[j]) {
                    q->board[pos]--;
                }
            } 
        }
    }
}

int main(){
    struct queen q;
    int n;
    printf("請輸入皇后數：");
    scanf("%d", &n);
    initQueen(&q, n);
    putQueen(&q, 1);
    printf("八皇后問題共有%d組解\n", q.solutions);
    return 0;
}
