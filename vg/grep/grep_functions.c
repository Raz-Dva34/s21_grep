//
// Created by Killed Hizdahr on 02.12.2022.
//
#include "s21_grep.h"

void funkcii(int argc, char *argv[], char *rez, int countfile,
             t_options *options, regex_t regex) {
  regmatch_t pmatch[1] = {0};
  FILE *f = NULL;
  int countn = 0;
  int countc = 0;
  int counts = 0;
  int regcount = 0;
  for (int i = optind; i < argc; i++) {
    if (argv[i][0] != '-') {
      if ((f = fopen(argv[i], "r")) != NULL) {
        while (fgets(rez, VOLUME, f) != NULL) {
          countn++;
          regcount = regexec(&regex, rez, 1, pmatch, 0);
          if (((options->v && options->c) ||
               (!options->c && !options->l && options->f && options->e)) &&
              regcount != 0)
            countc++;
          if (((!options->c && !options->v) || (!options->v || !options->f)) &&
              !options->v && regcount == 0)
            countc++;
          if (strchr(rez, '\n') == NULL)
            strcat(rez, "\n");
          if ((options->n || options->i || options->s) && regcount == 0 &&
              !options->e && !options->h && !options->v && !options->c &&
              !options->l && countfile > 1)
            printf("%s:", argv[i]);
          if (options->e && !options->c && !options->l && !options->v &&
              !options->h && regcount == 0 && countfile > 1)
            printf("%s:", argv[i]);
          if (options->f && !options->c && !options->v)
            printf("%s", rez);
          if (options->n && !options->v && !options->l &&
              regcount == 0) // FLAG -n
            printf("%d:", countn);
          if (options->v && !options->c && !options->l && regcount != 0) {
            if (countfile > 1 && !options->h)
              printf("%s:", argv[i]);
            if (options->n) {
              printf("%d:", countn);
            }
            printf("%s", rez);
          }
          if ((!options->l && !options->o && !options->v && !options->c) &&
              regcount == 0)
            printf("%s", rez);
        }
        if (options->c) {
          if (countfile > 1 && !options->h) {
            printf("%s:%d\n", argv[i], countc);
          } else if (!options->e && countfile <= 1) {
            printf("%d\n", countc);
          } else {
            printf("%d\n", countc);
          }
        }
        if (options->l) {
          if (countfile > 2) {
            printf("%s\n", argv[i]);
          } else if (countfile <= 2) {
            printf("%s\n", argv[i]);
          }
        }
        fclose(f);
        countc = 0;
        countn = 0;
      } else if (f == NULL) {
        counts++;
        if (!options->s && counts > 1)
          fprintf(stderr, "grep: %s: No such file or directory\n", argv[i]);
      }
    }
  }
  regfree(&regex);
}