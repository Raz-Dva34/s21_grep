//
// Created by Killed Hizdahr on 03.12.2022.
//
#include <string.h>
#include "s21_grep.h"
// n. h
void flago(int argc, char *argv[], char *buff, t_options *options, regex_t regex) {
    // (void) buff;
    regmatch_t pmatch[1];
    FILE *f = NULL;
    //char rezo[VOLUME];
    int regcounto;
    int filecount = 0;
    int stringcount = 0;
    int stringcountn = 0;
    int matchcount = 0;
    // char *s = buff;
    if ((argc - optind) > 1)
        filecount++;
    for (int i = optind; i < argc; i++) {
        if (argv[i][0] != '-') {
            if ((f = fopen(argv[i], "r")) != NULL) {
                while ((fgets(buff, 2000, f)) != NULL) {
                    stringcount++;
                    stringcountn++;
                    while ((regcounto = regexec(&regex, buff, 1, pmatch, 0)) == 0) {
                        matchcount++;
                        if (filecount > 0 && stringcount == matchcount && !options->h) {
                            printf("%s:", argv[i]);
                        }
                        if (options->n && stringcount == matchcount) {
                            printf("%d:", stringcountn);
                        }
                        int j;
                        for (j = pmatch[0].rm_so; j < pmatch[0].rm_eo; ++j) {
                            printf("%c", buff[j]);
                        }
                        printf("\n");
                        buff += pmatch[0].rm_eo;
                    }
                    stringcount = 0;
                    matchcount = 0;
                }
                stringcountn = 0;
            }
        }
    }
    regfree(&regex);
    fclose(f);
}