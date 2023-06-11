#include<stdio.h>

#define PAGE_SIZE 10
#define BUFFER_SIZE 256

void more(FILE* file) {
        char buffer[BUFFER_SIZE];
        int lineCount = 0;

        while(fgets(buffer, BUFFER_SIZE, file) != NULL) {
                printf("%s", buffer);
                lineCount++;

                if(lineCount == PAGE_SIZE) {
                        printf("-- More --");
                        getchar();
                        lineCount = 0;
                }
        }
}

int main(int argc, char* argv[]) {
        if(argc != 2) {
                printf("%s <파일이름>\n", argv[0]);
                return 1;
        }

        FILE* file = fopen(argv[1], "r");
        if(file == NULL) {
                printf("파일 열기를 실패했습니다.\n");
                return 1;
        }

        more(file);

        fclose(file);

        return 0;
}
