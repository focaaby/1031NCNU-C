#include <stdio.h>
#include <time.h> //caculate time


/*
*	Selection sort 2014/11/21
*	Bubble sort
*
*/

//Bubble sort
void bubble_sort(double x[], int n) {
    int i, j;
    double tmp;
    for(i = n-1; i >= 1; i = i - 1) {
        //bubble 1~i
        for(j = 1; j <= i; j = j + 1) {
            if (x[j-1] > x[j]) {    //順序不對
                tmp = x[j-1];
                x[j-1] = x[j];
                x[j] = tmp;
            }
        }
    }
}

void insertion_sort(double x[], int n) {
    int i, j;
    double tmp;
    // try to insert element i
    // 只有一個元素的綻裂就是排好的, 所以i由開始即可
    for(i = 1; i < n; i = i+1) {
        //先copy到tmp, 以便空出i位置
        tmp = x[i];
        //j 代表要比較的元素位置
        for(j = i-1; j >= 0 && x[j] >tmp; j = j -1) {
            //往後移動
            x[j+1] = x[j];
        }
        //此時該元素要放到j+1的位置   
        x[j+1] = tmp; 
    }
}

int isSorted(int x[], int n) {
    int i;
    for (i =0; i < n-1; i++) {
        if (x[i] > x[i+1]) 
            return 0;
    return 1;
}

int main() {
    int n, j;
    scanf("%d", &n);
    double x[n];

    clock_t start, end; //caculate time variable
    for(j = 1; j <= n; j++) {
        scanf("%lf", &x[j]);
    }
    

    start = clock();
    //caculate programm time
//    bubble_sort(x, n);
    insertion_sort(x, n);
    end = clock();
    
    double time = end - start; //ms
    
    //print after bubble sort
    for(j = 1; j <= n; j++) {
        printf("%lf ", x[j]);
    }
    printf("\n");
    printf("Use time(ms) %lf\n",time);
    printf("Use time %lf\n",time / CLOCKS_PER_SEC);
    return 0;
}
