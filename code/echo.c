#include<stdio.h>

int main(int argc, char *argv[]) {
        if(argc < 2) {
                fprintf(stderr, "%s [문자열]\n", argv[0]);
                return 1;
        }

        for(int i=1; i < argc; i++) {
                printf("%s", argv[i]);
                if(i < argc -1) {
                        printf(" ");
                }
        }
        printf("\n");

        return 0;
}
