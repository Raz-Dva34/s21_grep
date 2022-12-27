//
// Created by Killed Hizdahr on 02.12.2022.
//
#include "s21_grep.h"

void parcer(int argc, char *argv[], t_options *options, char *buff) {
  int opt = 0;
  while ((opt = getopt_long(argc, argv, "e:ivclnhsf:o", 0, 0)) != -1) {
    if (argc <= 1) {
      fprintf(stderr,
              "usage: grep [-abcDEFGHhIiJLlmnOoqRSsUVvwxZ] [-A num] [-B num] "
              "[-C[num]]\n"
              "\t[-e pattern] [-f file] [--binary-files=value] [--color=when]\n"
              "\t[--context[=num]] [--directories=action] [--label] "
              "[--line-buffered]\n"
              "\t[--null] [pattern] [file ...]");
      exit(EXIT_SUCCESS);
    } else {
      options->v = (options->v || opt == 'v') ? true : false;
      options->i = (options->i || opt == 'i') ? true : false;
      options->c = (options->c || opt == 'c') ? true : false;
      options->l = (options->l || opt == 'l') ? true : false;
      options->n = (options->n || opt == 'n') ? true : false;
      options->h = (options->h || opt == 'h') ? true : false;
      options->s = (options->s || opt == 's') ? true : false;
      options->e = (options->e || opt == 'e') ? true : false;
      options->o = (options->o || opt == 'o') ? true : false;
      options->f = (options->f || opt == 'f') ? true : false;
      if (options->f && options->e)
        options->e = false;
      if (options->v)
        options->o = false;
      if (options->c || options->l) {
        options->n = false;
        options->o = false;
      }
      if (options->e && opt == 'e' && !options->f) {
        flage(buff);
      }
      if (options->f && opt == 'f')
        flagf(optarg, buff);
    }
  }
}