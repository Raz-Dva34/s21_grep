
#include "s21_grep.h"

int main(int argc, char *argv[]) {
  char buff[2000] = "\0";
  regex_t regex;
  t_options options;
  parcer(argc, argv, &options, buff, regex);
  reader(argc, argv, &options, regex);
//output_flag_data(&options);
  //free(buff);
  return 0;
}


