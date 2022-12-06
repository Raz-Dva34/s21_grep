//
// Created by Killed Hizdahr on 02.12.2022.
//
#include "s21_grep.h"

void parcer(int argc, char *argv[], t_options *options, char *buff, regex_t regex) {
  int opt;
  while ((opt = getopt_long(argc, argv, "e:ivclnhsf:o", 0, 0)) != -1) {
    options->v = (options->v || opt == 'v') ? true : false;
    options->i = (options->i || opt == 'i') ? true : false;
    options->c = (options->c || opt == 'c') ? true : false;
    options->l = (options->l || opt == 'l') ? true : false;
    options->n = (options->n || opt == 'n') ? true : false;
    options->h = (options->h || opt == 'h') ? true : false;
    options->s = (options->s || opt == 's') ? true : false;
    //options->f = (!options->f || opt == 'f') ? true : false;
    options->o = (options->o || opt == 'o') ? true : false;
    if (opt == 'o')
      flago(argc, argv, buff, regex);
    if (opt == 'e')
      flage(buff);
    if (opt == 'f')
      flagf(argv, buff);
  }
//  if (options->c && options->l)
//    options->c = false;
  if (options->i && options->v)
    options->i = false;
  if (options->c || options->l) {
    options->i = false;
    options->e = false;
    options->n = false;
    options->o = false;
    options->s = false;
    options->h = false;
    // options->f = false;
    options->v = false;
  }
  //printf("%s", buff);
}