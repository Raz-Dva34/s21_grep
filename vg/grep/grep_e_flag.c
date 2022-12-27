//
// Created by Killed Hizdahr on 02.12.2022.
//
#include "s21_grep.h"

void flage(char *buff) {
  if (*buff != '\0') {
    strcat(buff, "|");
  }
  strcat(buff, optarg);
}