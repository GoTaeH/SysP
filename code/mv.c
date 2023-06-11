#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>

int main(int argc, char *argv[]) {
        if(argc < 3) {
                fprintf(stderr, "%s [소스파일] [대상파일/디렉토리]\n", argv[0]);
                return 1;
        }

        struct stat target_stat;
        int is_directory = 0;

        if(stat(argv[2], &target_stat) == 0 && S_ISDIR(target_stat.st_mode)) {
                is_directory = 1;
        }

        if(is_directory) {
                char destination[256];
                char *filename = strrchr(argv[1], '/');
                if(filename != NULL) {
                        strcpy(destination, argv[2]);
                        strcat(destination, filename);
                } else {
                        sprintf(destination, "%s/%s", argv[2], argv[1]);
                }

                if(rename(argv[1], destination) == 0) {
                        printf("파일이 성공적으로 이동되었습니다.\n");
                } else {
                        perror("파일 이동 오류");
                }
        } else {
                if(rename(argv[1], argv[2]) == 0) {
                        printf("파일이 성공적으로 이동/이름 변경되었습니다.\n");
                } else {
                        perror("파일 이동/이름 변경 오류");
                }
        }

        return 0;
}
