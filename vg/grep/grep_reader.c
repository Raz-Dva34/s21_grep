//
// Created by Killed Hizdahr on 02.12.2022.
//
#include "s21_grep.h"

void reader(int argc, char *argv[], char *buff, char *rez, int countfile,
            t_options *options, regex_t regex) {
  char *pattern = argv[optind];
  int cflags = 0;
  for (int i = optind; i < argc; i++) {
    if ((argc - optind) > 1)
      countfile++;
  }
  if (options->v || (options->v && options->c))
    cflags = REG_NOMATCH;
  if (options->f || (options->f && options->c) || (options->f && options->v)) {
    options->e = false;
    pattern = buff;
    cflags = REG_EXTENDED;
  }
  if (options->e || (options->e && !options->f && !options->l) ||
      (options->e && options->c)) {
    pattern = buff;
    cflags = REG_EXTENDED;
  }
  if (options->i || (options->i && options->c))
    cflags = REG_ICASE;
  regcomp(&regex, pattern, cflags);
  if (options->o) {
    flago(argc, argv, buff, options, regex);
  } else {
    funkcii(argc, argv, rez, countfile, options, regex);
  }
}