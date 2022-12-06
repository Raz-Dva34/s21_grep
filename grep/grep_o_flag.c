//
// Created by Killed Hizdahr on 03.12.2022.
//

#include "s21_grep.h"

void flago(int argc ,char *argv[], char *buff, regex_t regex) {
  (void )buff;
  regmatch_t pmatch[1];
  FILE *f = NULL;
  char rezo[VOLUME];
  int regcounto;
  char *s = rezo;
  for (int i = optind; i < argc; i++) {
    if (argv[i][0] != '-') {
      if ((f = fopen(argv[i], "r")) != NULL) {
        while ((fgets(s, VOLUME, f)) != NULL) {
          while ((regcounto = regexec(&regex, s, 1, pmatch, 0)) == 0) {
            printf("11111");
            printf("%d", regcounto);
            if (regcounto == 0) {
              if (argc > 4) {
                printf("%s:", argv[i]);
              }
              for (int j = pmatch[0].rm_so; j < pmatch[0].rm_eo; j++) {
                printf("%c", s[j]);
              }
              printf("\n");
            }
            s += pmatch[0].rm_eo;
          }
        }
        fclose(f);
        regfree(&regex);
      }
    }
  }
}
