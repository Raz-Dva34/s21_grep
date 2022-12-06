//
// Created by Killed Hizdahr on 30.10.2022.
//
#ifndef S21_GREP_H
#define S21_GREP_H

#define VOLUME 500

#include <stdbool.h>
#include <stdio.h>
#include <getopt.h>
#include <regex.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_options {
  bool e; //Шаблон
  bool i; //Игнорирует различия регистра.
  bool v; //Инвертирует смысл поиска соответствий.
  bool c; //Выводит только количество совпадающих строк.
  bool l; //Выводит только совпадающие файлы.
  bool n; //Предваряет каждую строку вывода номером строки из файла ввода.
  bool h; //Выводит совпадающие строки, не предваряя их именами файлов.
  bool s; //Подавляет сообщения об ошибках о несуществующих или нечитаемых файлах.
  // bool f; //Получает регулярные выражения из файла.
  bool o; //Печатает только совпадающие (непустые) части совпавшей строки.
} t_options;

void parcer(int argc, char *argv[], t_options *options, char *buff, regex_t regex);
void flage(char buff[2000]);
void funkcii(int argc, char *argv[], t_options *options, regex_t regex);
void reader(int argc, char *argv[], t_options *options, regex_t regex);
void flagf(char *argv[], char *buff);
void output_flag_data(t_options *options);
void flago(int argc, char *argv[], char *buff, regex_t regex);

#endif //S21_GREP_H
