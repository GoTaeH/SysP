#include<stdio.h>
#include<time.h>

int main() {
        time_t current_time;
        struct tm *time_info;
        char time_string[80];

        time(&current_time);
        time_info = localtime(&current_time);
        strftime(time_string, sizeof(time_string), "%a %b %d %H:%M:%S %Z %Y", time_info);

        printf("%s\n", time_string);

        return 0;
}
