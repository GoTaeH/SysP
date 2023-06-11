#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() {
        char *username = getenv("USER");
        if(username == NULL) {
                perror("사용자 이름을 가져오는 데 실패했습니다.");
                return 1;
        }

        printf("%s\n", username);

        return 0;
}
