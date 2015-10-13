#include <stdio.h>
int main() {
    int row, col;
    for (row = 1; row <=9; row = row + 1) {
        for(col = 1; col <= 9; col = col + 1) {
            printf("%3d ", row * col);
        }
        printf("\n");
    }
    return 0;
}
