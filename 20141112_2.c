#include <stdio.h>
#include <stdlib.h>

//rand() is a functuon randomly returns val which 0 <= val <1
//四捨五入到小數點下digit位
double myround (double x, int digit) {
    int i;
    for (i = 1; i <= digit; i++) 
        x = x * 10;
    x = (double)((int)(x + 0.5));
    for (i = 1; i <= digit; i++) 
        x = x / 10;
    return x;
}
//returns an integer rel, where a <= rel <= b

int main() {
    double x =  1.23435678;
    //(datatype) casting 強制轉型

    //how to 無條件捨去小數點下一位？
    printf("%f\n", (int)(x*10)/10.0);
    //how to 無條件捨去小數點下兩位？
    printf("%f\n", (int)(x*100)/100.0);

    //如何作四捨五入
    printf("%lf, after round %f\n",x ,(int)(x + 0.5));
    //如何作四捨五入小數點下一位？
    printf("%lf, after round %f\n",x ,(int)(x * 10 + 0.5)/10.0);
    //如何作四捨五入小數點下兩位？
    printf("%lf, after round %f\n",x ,(int)(x * 100 + 0.5)/100.0);
    
    return 0;
}
