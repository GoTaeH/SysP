#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>

int main(int argc, char *argv[]) {
        if(argc < 2) {
                fprintf(stderr, "%s [디렉토리 이름]\n", argv[0]);
                return 1;
        }

        if(mkdir(argv[1], 0777) == 0) {
                printf("디렉토리가 성공적으로 생성되었습니다.\n");
        } else {
                perror("디렉토리 생성 오류");
        }

        return 0;
}
