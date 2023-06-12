#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 1024

// tail 명령어 실행 함수
void tail(const char* filename, int numLines) {
    char* lines[MAX_LINES];
    int lineCount = 0;
    char line[MAX_LINE_LENGTH];

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return;
    }

    // 파일에서 각 줄을 읽어와 배열에 저장
    while (fgets(line, sizeof(line), file) != NULL) {
        if (lineCount >= MAX_LINES) {
            // 배열 크기 초과 시, 가장 오래된 줄 제거
            free(lines[0]);
            memmove(lines, lines + 1, (lineCount - 1) * sizeof(char*));
            lineCount--;
        }

        line[strcspn(line, "\n")] = '\0';

        // 배열에 줄 추가
        lines[lineCount] = strdup(line);
        lineCount++;
    }

    fclose(file);

    // 출력할 줄 수 계산
    int startLine = lineCount - numLines;
    if (startLine < 0) {
        startLine = 0;
    }

    // 정해진 범위 내의 줄 출력
    for (int i = startLine; i < lineCount; i++) {
        printf("%s\n", lines[i]);
        free(lines[i]);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("%s <파일명> <줄 수>\n", argv[0]);
        return 1;
    }

    int numLines = atoi(argv[2]);

    tail(argv[1], numLines);

    return 0;
}
