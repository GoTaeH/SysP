#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void grep(const char* pattern, const char* fname, int showNum) {
        FILE* file = fopen(fname, "r"); //읽기 모드
        if(file == NULL) {
                printf("파일을 열 수 없습니다.\n");
                return;
        }

        char line[256];
        int lineNum = 0;

        while(fgets(line, sizeof(line), file) != NULL) {
                lineNum++;

                if(strstr(line, pattern) != NULL) {
                        if(showNum) {
                                printf("%d:", lineNum);
                        }
                        printf("%s", line);
                }
        }

        fclose(file);

}

int main(int argc, char* argv[]) {
        if(argc < 3) {
                printf("%s [옵션] <패턴> <파일명>\n", argv[0]);
                return 1;
        }

        int showNum = 0;
        int patternIdx = 1;
        int fnameIdx = 2;

  // grep -n 옵션
        if(argc >= 4 && strcmp(argv[1], "-n") == 0) {
                showNum = 1;
                patternIdx++;
                fnameIdx++;
        }

        const char* pattern = argv[patternIdx];
        const char* fname = argv[fnameIdx];

        grep(pattern, fname, showNum);

        return 0;
}
