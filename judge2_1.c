#include <stdio.h>

void getrand(int *num) {
    int i;
    for(i = 0; i < 6; i++)
        num[6] = rand() % 38 + 1;
}



int main() {
    int num[6];
     
