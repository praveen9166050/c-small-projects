#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

void fill_time(char*, int);
void fill_date(char*);
int input_format();
void clear_screen();

int main(int argc, char const *argv[])
{
    char time[50], date[100];
    int format = input_format();
    while (1) {
        clear_screen();
        fill_time(time, format);
        fill_date(date);
        printf("Current time: %s\n", time);
        printf("Current date: %s\n", date);
        sleep(1);
    }
    
    return 0;
}

int input_format() {
    printf("Choose the time formate\n");
    printf("1. 24 hours format\n");
    printf("2. 12 hours format (default)\n");

    int format;
    printf("Make a choice: ");
    scanf("%d", &format);

    return format;
}

void fill_time(char *buffer, int format) {
    time_t raw_time;
    struct tm *current_time;
    
    time(&raw_time);
    current_time = localtime(&raw_time);
    if (format == 1) {
        strftime(buffer, 50, "%H:%M:%S", current_time);
    } else {
        strftime(buffer, 50, "%I:%M:%S %p", current_time);
    }
}

void fill_date(char *buffer) {
    time_t raw_time;
    struct tm *current_time;
    
    time(&raw_time);
    current_time = localtime(&raw_time);

    strftime(buffer, 100, "%A %d %B %Y", current_time);
}

void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}