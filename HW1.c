#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    printf("Ans1=%lf\nAns2=%lf\n",(-b+sqrt(b*b-4*a*c))/2/a, (-b-sqrt(b*b-4*a*c))/2/a);
    return 0;
}

