#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
        if(argc < 3) {
                printf("%s <현재 파일 이름> <새로운 파일 이름> \n", argv[0]);
                return 1;
        }

        const char *oldname = argv[1];
        const char *newname = argv[2];

        int result = rename(oldname, newname);
        if(result == 0) {
                printf("파일 이름을 변경했습니다.\n");
        } else {
                perror("파일 이름 변경 오류");
        }

        return 0;
}
