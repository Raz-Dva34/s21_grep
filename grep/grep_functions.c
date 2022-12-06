//
// Created by Killed Hizdahr on 02.12.2022.
//
#include "s21_grep.h"

void funkcii(int argc, char *argv[], t_options *options, regex_t regex) {
  regmatch_t pmatch[1];
  FILE *f = NULL;
  char rez[1024];
  int countn = 0;
  int countc = 0;
  int regcount;
  for (int i = optind; i < argc; i++) {
    if (argv[i][0] != '-') {
      if ((f = fopen(argv[i], "r")) != NULL) {
        while (fgets(rez, VOLUME, f) != NULL) {
          countn++;
          if ((regcount = regexec(&regex, rez, 1, pmatch, 0)) == 0) {
            countc++;
            if ((options->n || options->i) && regcount == 0 && argc > 4)
              printf("%s:", argv[i]);
            if (options->n && regcount == 0)  // FLAG -n
              printf("%d:", countn);
            if (options->i && regcount == 0)  // FLAG -i
              printf("%s", rez);
            if (options->h && regcount == 0)
              printf("%s", rez);
            if (options->l && regcount == 0) {
              if (argc > 4) {
                printf("%s\n", argv[i]);
                break;
              } else if (argc <= 4) {
                printf("%s", argv[i]);
                break;
              }
            }
            if ((!options->l && !options->o && !options->v && !options->c && !options->i) && regcount == 0)
              printf("%s", rez);
          } else if (regcount != 0) {
            if (options->v) {
              if (argc > 4) {
                if (!options->h) {
                  printf("%s:", argv[i]);
                }
                printf("%s", rez);
              } else if (argc <= 4) {
                printf("%s", rez);
              }
            }
          }
        }
        if (options->c) {
          if (argc > 4)
            printf("%s:%d\n", argv[i], countc);
          else if (argc <= 4)
            printf("%d", countc);
        }
        fclose(f);
        countc = 0;
        countn = 0;
      } else {
        if (!options->s) { //выводит ошибку на не открывающийся файл
          //fprintf(stderr, "grep: %s: No such file or directory\n", argv[i]); //write
          //  continue; //мб пригодится
        }
      }
    }
  }
}
