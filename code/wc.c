#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    int wordCount;
    int lineCount;
    int charCount;
} WCResult;

// wc 명령어 실행 함수
WCResult wc(const char* filename) {
    WCResult result = {0, 0, 0};
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return result;
    }

    int inWord = 0;
    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), file) != NULL) {
        result.lineCount++;

        for (int i = 0; line[i] != '\0'; i++) {
            if (isspace(line[i])) {
                inWord = 0;
            } else {
                if (!inWord) {
                    result.wordCount++;
                    inWord = 1;
                }
            }

            result.charCount++;
        }
    }

    fclose(file);

    return result;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("%s <파일명>\n", argv[0]);
        return 1;
    }

    WCResult result = wc(argv[1]);

    printf("%d %d %d %s\n", result.lineCount, result.wordCount, result.charCount, argv[1]);

    return 0;
}
