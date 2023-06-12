#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 1024

int compareStrings(const void* a, const void* b) {
    const char* strA = *(const char**)a;
    const char* strB = *(const char**)b;

    return strcmp(strA, strB);
}

// sort 명령어 실행 함수
void sort(const char* filename) {
    char* lines[MAX_LINES];
    int numLines = 0;
    char line[MAX_LINE_LENGTH];

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        if (numLines >= MAX_LINES) {
            printf("파일 크기가 너무 큽니다.\n");
            return;
        }

        // 개행 문자 제거
        line[strcspn(line, "\n")] = '\0';

        // 배열에 줄 추가
        lines[numLines] = strdup(line);
        numLines++;
    }

    fclose(file);

    // 문자열 배열 정렬
    qsort(lines, numLines, sizeof(char*), compareStrings);

    // 정렬된 결과 출력
    for (int i = 0; i < numLines; i++) {
        printf("%s\n", lines[i]);
        free(lines[i]);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("%s <파일명>\n", argv[0]);
        return 1;
    }

    sort(argv[1]);

    return 0;
}
