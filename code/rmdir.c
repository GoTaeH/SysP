#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char* argv[]) {
        if(argc < 2) {
                printf("%s <디렉토리 경로>\n", argv[0]);
                return 1;
        }

        const char* path = argv[1];

        if(rmdir(path) == 0) {
                printf("디렉토리를 성공적으로 제거했습니다: %s\n", path);
        } else {
                perror("디렉토리 제거 실패");
        }

        return 0;
}
