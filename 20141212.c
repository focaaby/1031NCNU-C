#include <stdio.h>
/*

a.exe a b c d
main( )
**argc ->|_|
         |_|
         |_|
         |_|
*/
int main(int argc, char **argv) {
    int i;
    for (i = 0; i < argc; i++) {
        printf("%s\n", *(argv+i));
    }
    return 0;
}

/*
int main(int argc, char *argv[]) {
    int i;
    for (i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }
    return 0;
}

*/
