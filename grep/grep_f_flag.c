//
// Created by Killed Hizdahr on 02.12.2022.
//
#include "s21_grep.h"

void flagf(char *argv[], char *buff) {
  FILE *f = NULL;
  char rezf[VOLUME];
  if ((f = fopen(argv[optind], "r")) != NULL) {
    while (fgets(rezf, VOLUME - 1, f)) {
      strcat(buff, rezf);
//      int dstr = strlen(buff);
//      if (buff[dstr - 1] == '\n') {
//        buff[dstr - 1] = '|';
//      }
//      flage(buff);// переместить в main?
    }
    printf("%s", buff);
    fclose(f);
  }
}