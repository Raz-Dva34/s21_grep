//
// Created by Killed Hizdahr on 02.12.2022.
//
#include "s21_grep.h"

void reader(int argc, char *argv[], t_options *options, regex_t regex) {
  char *pattern = argv[optind];
  if (options->i) {
    regcomp(&regex, pattern, REG_ICASE);
  }
  if (options->v) {
    regcomp(&regex, pattern, REG_NOMATCH);
  }
  if (options->e) {
    regcomp(&regex, pattern, REG_EXTENDED);
  }
  regcomp(&regex, pattern, 0);

  funkcii(argc, argv, options, regex);
}
