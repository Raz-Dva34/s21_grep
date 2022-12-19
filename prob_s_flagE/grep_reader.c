//
// Created by Killed Hizdahr on 02.12.2022.
//
#include "s21_grep.h"

void reader(int argc, char *argv[], char *buff, char *rez, t_options *options, regex_t regex) {
    char *pattern = argv[optind];
    int cflags = 0;

    if (options->v) {
        cflags = REG_NOMATCH;
    }
    if (options->f) {
        options->e = false;
        pattern = buff;
        cflags = REG_EXTENDED;
    }
    if (options->e && !options->f) {
        pattern = buff;
        cflags = REG_EXTENDED;
    }

    if (options->i) {
        cflags = REG_ICASE;
    }
    if (options->c) {
        cflags = REG_EXTENDED;
    }
    regcomp(&regex, pattern, cflags);

    if (options->o) {
        flago(argc, argv, buff, options, regex);
    } else {
        funkcii(argc, argv, rez, options, regex);
    }
}