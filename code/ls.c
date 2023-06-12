#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<unistd.h>

int main(void)
{
        char * cwd = (char *)malloc(sizeof(char) * 1024);
        DIR * dir = NULL;
        struct dirent * entry = NULL;

        getcwd(cwd,1024);

        if((dir = opendir(cwd)) == NULL) {
                printf("current directory error\n");
                exit(1);
        }

        while((entry = readdir(dir)) != NULL) {
                printf("%s ", entry->d_name);
        }

        printf("\n");
        free(cwd);
        closedir(dir);

        return 0;
}
