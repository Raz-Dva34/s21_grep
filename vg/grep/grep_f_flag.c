//
// Created by Killed Hizdahr on 02.12.2022.
//
#include "s21_grep.h"

void flagf(char *filename, char *buff) {
  FILE *f = NULL;
  char rezf[VOLUME] = {0};
  int dstr = 0;
  if ((f = fopen(filename, "r")) != NULL) {
    while (fgets(rezf, VOLUME - 1, f)) {
      strcat(buff, rezf);
      dstr = strlen(buff);
      if (buff[dstr - 1] == '\n') {
        buff[dstr - 1] = '|';
      }
    }
    buff[dstr] = '\0';
    fclose(f);
  }
}