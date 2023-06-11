#include<stdio.h>
#include<stdlib.h>
#include<utime.h>
#include<sys/stat.h>

int main(int argc, char *argv[]) {
        if(argc < 2) {
                fprintf(stderr, "%s [파일 이름]\n", argv[0]);
                return 1;
        }

        struct stat st;
        if(stat(argv[1], &st) == 0) {
                // 이미 파일 존재함 -> 수정 시간 업데이트
                utime(argv[1], NULL);
        } else {
                //파일 존재하지 않음 -> 빈 파일 생성
                FILE *file = fopen(argv[1], "w");
                if(file != NULL) {
                        fclose(file);
                } else {
                        perror("파일 생성 오류");
                        return 1;
                }
        }

        printf("파일이 성공적으로 생성되었습니다.\n");

        return 0;
}
