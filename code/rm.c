#include<stdio.h>

int main(int argc, char *argv[]) {
        if(argc < 2) {
                fprintf(stderr, "%s [파일이름]\n", argv[0]);
                return 1;
        }

        if(remove(argv[1]) == 0) {
                printf("파일이 성공적으로 삭제되었습니다.\n");
        } else {
                perror("파일 삭제 오류");
        }

        return 0;
}
