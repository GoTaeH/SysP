#include<stdio.h>

void head(const char* filename, int n) {
        FILE* file = fopen(filename, "r");
        if(file == NULL) {
                fprintf(stderr, "파일을 열 수 없습니다: %s\n", filename);
                return;
        }

        char line[1024];
        int line_cnt = 0;

        while(fgets(line, sizeof(line), file) != NULL) {
                printf("%s", line);
                line_cnt++;

                if(line_cnt == n) {
                        break;
                }
        }
        fclose(file);
}

int main(int argc, char* argv[]) {
        if(argc < 3) {
                fprintf(stderr, "%s <파일명> <출력할 라인 수>\n", argv[0]);
                return 1;
        }

        const char* filename = argv[1];
        int n = atoi(argv[2]);

        head(filename, n);

        return 0;
}
