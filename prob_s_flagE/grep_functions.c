//
// Created by Killed Hizdahr on 02.12.2022.
//
#include "s21_grep.h"

void funkcii(int argc, char *argv[], char *rez, t_options *options, regex_t regex) {
    regmatch_t pmatch[1];
    FILE *f = NULL;
    int countn = 0;
    int countc = 0;
    int countfile = 0;
    int countfilec = 5;
    int regcount;
    for (int i = optind; i < argc; i++) {
        if ((argc - optind) > 1)
            countfile++;
        if (argv[i][0] != '-') {
            if ((f = fopen(argv[i], "r")) != NULL) {
                while (fgets(rez, VOLUME, f) != NULL) {
                    /*         if (*rez == '\0') {
                               strcat(rez, "\n");
                             }*/
                    countn++;
                    regcount = regexec(&regex, rez, 1, pmatch, 0);
                    if (regcount == 0)
                        countc++;
                    if ((options->n || options->i || options->s) && regcount == 0 && !options->e
                        && !options->h && !options->v && countfile > 1)
                        printf("%s:", argv[i]);
                    if (options->e && !options->c && regcount == 0 && countfile > 0)
                        printf("%s:", argv[i]);
                    if (options->n && !options->v && regcount == 0)  // FLAG -n
                        printf("%d:", countn);
                    if (options->v && regcount != 0) {
                        if (argc > 4 && !options->h) {
                            printf("%s:", argv[i]);
                        }
                        if (options->n) {
                            printf("%d:", countn);
                        }
                        printf("%s", rez);
                    }
                    if (options->l && regcount == 0) {
                        if (argc > 4) {
                            printf("%s\n", argv[i]);
                            break;
                        } else if (argc <= 4) {
                            printf("%s", argv[i]);
                            break;
                        }
                    }
                    if ((!options->l && !options->o && !options->v && !options->c) && regcount == 0) {
                        printf("%s", rez);
                    }
                }
                if (options->c) {
                    if ((countfile > 0 && options->e) || (!options->e && countfilec < 5)) {
                        printf("%s:%d\n", argv[i], countc);
                    } else if (!options->e && countfile >= 2) {
                        printf("%d\n", countc);
                    } else {
                        printf("%d\n", countc);
                    }
                }
                regfree(&regex);
                fclose(f);
                countc = 0;
                countn = 0;
            } else if (f == NULL) {
                if (!options->s && countfile != 0) { //выводит ошибку на не открывающийся файл
                    //   fprintf(stderr, "grep: %s: No such file or directory\n", argv[i]); //write
                    //мб пригодится*/
                }
            }
        }
    }
}