#include "s21_grep.h"

int main(int argc, char *argv[]) {
  if (argc > 2) {
    char buff[2000] = "\0";
    char rez[1024] = "\0";
    int countfile = 0;
    regex_t regex = {0};
    t_options options = {0};
    parcer(argc, argv, &options, buff);
    reader(argc, argv, buff, rez, countfile, &options, regex);
    // for;
    // regex;
    // print;
    // while;
    // free(buff);
  } else
    return 0;
}
