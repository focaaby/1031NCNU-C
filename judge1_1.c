#include <stdio.h>

int main() {
    int i, n, count = 0, sum = 0;
    scanf("%d", &n); //how many number you want to input
    int input[n]; //input numbers
    for(i = 0; i < n; i++) {
        scanf("%d", &input[i]);
        sum += input[i];
    }
    for(i = 0; i < n; i++) {
        if(input[i] > (sum / n))
            count += input[i] - (sum/n);
    }
    printf("%d\n", count);
    return 0;
}
    
    
