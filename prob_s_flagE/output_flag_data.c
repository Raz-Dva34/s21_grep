//
// Created by Killed Hizdahr on 03.12.2022.
//
#include "s21_grep.h"

void output_flag_data(t_options *options){
    printf("\n|s = %d|\n", options->s);
    printf("|v = %d|\n", options->v);
    printf("|n = %d|\n", options->n);
    printf("|i = %d|\n", options->i);
    printf("|c = %d|\n", options->c);
    printf("|e = %d|\n", options->e);
    printf("|h = %d|\n", options->h);
    printf("|l = %d|\n", options->l);
    printf("|o = %d|\n", options->o);
    printf("|f = %d|\n", options->f);
}