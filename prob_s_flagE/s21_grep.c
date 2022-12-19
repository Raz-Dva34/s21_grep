
#include "s21_grep.h"

int main(int argc, char *argv[]) {
    char buff[2000] = "\0";
    char rez[1024];
    regex_t regex;
    t_options options;
    parcer(argc, argv, &options, buff);
    reader(argc, argv, buff, rez, &options, regex);
    output_flag_data(&options);
    //free(buff);
    return 0;
}