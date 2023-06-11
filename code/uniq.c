#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LINE_LENGTH 100

//파일에서 중복된 연속 라인 제거하는 함수
void rm_duplicates(const char* filename) {
        FILE* file = fopen(filename, "r");
        if(file == NULL) {
                printf("파일을 열 수 없습니다.\n");
                return;
        }

        char prevLine[MAX_LINE_LENGTH] = "";
        char line[MAX_LINE_LENGTH];

        while(fgets(line, sizeof(line), file) != NULL) {
                if(strcmp(line, prevLine) != 0) {
                        printf("%s", line);
                        strcpy(prevLine, line);
                }
        }

        fclose(file);
}

int main(int argc, char* argv[]) {
        if(argc != 2) {
                printf("%s <파일명>\n", argv[0]);
                return 1;
        }

        const char* filename = argv[1];

        rm_duplicates(filename);

        return 0;
}
