#include <stdio.h>
//open file

int main(int argc, char *argv[]) {
    int i, len;
    char buf[1000];
    FILE *f;
    if (argc == 2) {
        f =fopen(argv[1], "r"); //open with read only mod 
        if ( f == NULL) {
            printf("file open fail, please check filename and privilege\n");
            return 1;
        }   
        //while no End Of File, keep read in string
      /*  while (fscanf(f, "%s" buf) != EOF) {
            printf("%s\n", buf);
        }
      */
        //while no End Of File, keep read and output to stdout 
        while ((len = fread(buf, sizeof(char), sizeof(buf), f)) != 0) {
            fwrite(buf, 1, len, stdout);  //stdout -> print out to screen
        }
        fclose(f);
    } else {
        printf("please specify filename as the first argument\n");
    }
    return 0;
}
