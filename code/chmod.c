#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>

int main(int argc, char *argv[]) {
        if(argc < 3) {
                printf("%s <모드> <파일 이름>\n", argv[0]);
                return 1;
        }

        const char *mode_str = argv[1];
        const char *filename = argv[2];

        int mode = strtol(mode_str, 0, 8);
        if(chmod(filename, mode) != 0) {
                perror("chmod 오류");
                return 1;
        }

        printf("파일의 모드를 변경했습니다.\n");

        return 0;
}
