#include<stdio.h>

void cmp_files(const char* file1, const char* file2) {
        FILE* fp1 = fopen(file1, "rb");
        FILE* fp2 = fopen(file2, "rb");

        if(fp1 == NULL || fp2 == NULL) {
                printf("파일을 열 수 없습니다.\n");
                return;
        }

        int byte1, byte2;
        long position = 0;
        int difference = 0;
        int line = 1;

        while(1) {
                byte1 = fgetc(fp1);
                byte2 = fgetc(fp2);
                position++;

                if(byte1 != byte2) {
                        printf("%s %s differ: byte %ld, line %d\n", file1, file2, position, line);
                        difference = 1;
                        break;
                }

                if(byte1 == '\n' && byte2 == '\n') {
                        line++;
                }

                if(byte1 == EOF || byte2 == EOF)
                        break;
        }

        if(!difference) {
                printf("두 파일은 동일합니다.\n");
        }

        fclose(fp1);
        fclose(fp2);
}

int main(int argc, char* argv[]) {
        if(argc != 3) {
                printf("%s <파일1> <파일2>\n", argv[0]);
                return 1;
        }

        const char* file1 = argv[1];
        const char* file2 = argv[2];

        cmp_files(file1, file2);

        return 0;
}
