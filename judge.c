#include <stdio.h>
void print(int val, int base) {
    int i;
    char output[1000];
    for(i = 0 ;val != 0; i++, val /= base) {
        val%base < 9?(output[i]=(char)(val%base+'0')):(output[i]=(char)(val%base+'A'-10)); 
    }
    for( ;i >= 0 ;i--)
        printf("%c",output[i]);
    printf("\n");
}
int main() {
    int num, base;
    scanf("%d %d", &num, &base);
    print(num, base);
    return 0;
}
