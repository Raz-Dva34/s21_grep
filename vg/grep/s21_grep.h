//
// Created by Killed Hizdahr on 30.10.2022.
//
#ifndef S21_GREP_H
#define S21_GREP_H

#define VOLUME 1024

#include <getopt.h>
#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_options {
  bool e; //Шаблон
  bool i; //Игнорирует различия регистра.
  bool v; //Инвертирует смысл поиска соответствий.
  bool c; //Выводит только количество совпадающих строк.
  bool l; //Выводит только совпадающие файлы.
  bool n; //Предваряет каждую строку вывода номером строки из файла ввода.
  bool h; //Выводит совпадающие строки, не предваряя их именами файлов.
  bool s; //Подавляет сообщения об ошибках о несуществующих или нечитаемых
          //файлах.
  bool f; //Получает регулярные выражения из файла.
  bool o; //Печатает только совпадающие (непустые) части совпавшей строки.
} t_options;

void parcer(int argc, char *argv[], t_options *options, char *buff);
void flage(char *buff);
void funkcii(int argc, char *argv[], char *rez, int countfile,
             t_options *options, regex_t regex);
void reader(int argc, char *argv[], char *buff, char *rez, int countfile,
            t_options *options, regex_t regex);
void flagf(char *filename, char *buff);
void flago(int argc, char *argv[], char *buff, t_options *options,
           regex_t regex);

#endif // S21_GREP_H
