#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    if((b*b-4*a*c) > 0) {
        printf("%lf %lf\n",(-b+sqrt(b*b-4*a*c))/2/a, (-b-sqrt(b*b-4*a*c))/2/a);
    } else if( (b*b-4*a*c)== 0) {
        printf("%lf %lf\n",(-b+sqrt(b*b-4*a*c))/2/a, ((-b-sqrt(b*b-4*a*c))/2/a)  );
    } else {
     //   printf("%lf:b^2-4ac\n",+(b*b-4*a*c));
        printf("%lf+%lfi %lf%lfi\n",-b/2/a,sqrt(-(b*b-4*a*c))/2/a,-b/2/a,-(sqrt(-(b*b-4*a*c)))/2/a);
    }
    return 0;
}

