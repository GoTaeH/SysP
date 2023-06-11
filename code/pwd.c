#include<stdio.h>
#include<unistd.h>
char *getcwd(char *buf, size_t size);
char *getwd(char *buf);
char *get_currnet_dir_name(void);

int main(void) {
        char buf[BUFSIZ];

        getcwd(buf, BUFSIZ);
        printf("%s\n", buf);
}
