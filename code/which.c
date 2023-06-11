#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("사용법: %s [명령어]\n", argv[0]);
        return 1;
    }

    char* command = argv[1];

    // PATH 환경 변수 값을 가져옴
    char* path_env = getenv("PATH");
    if (path_env == NULL) {
        printf("PATH 환경 변수를 찾을 수 없습니다.\n");
        return 1;
    }

    // PATH 환경 변수 값을 ':'을 기준으로 토큰화하여 검색
    char* path = strtok(path_env, ":");
    while (path != NULL) {
        // 명령어와 경로를 조합하여 절대 경로 생성
        char absolute_path[256];
        snprintf(absolute_path, sizeof(absolute_path), "%s/%s", path, command);

        // 실행 가능한 파일인지 확인
        if (access(absolute_path, X_OK) == 0) {
            printf("%s\n", absolute_path);
            return 0;
        }

        path = strtok(NULL, ":");
    }

    // 실행 가능한 경로를 찾지 못한 경우
    printf("'%s'을(를) 찾을 수 없습니다.\n", command);
    return 1;
}
