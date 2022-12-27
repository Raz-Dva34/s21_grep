//
// Created by Killed Hizdahr on 03.12.2022.
//
#include "s21_grep.h"
#include <string.h>

void flago(int argc, char *argv[], char *buff, t_options *options,
           regex_t regex) {
  regmatch_t pmatch[1] = {0};
  FILE *f = NULL;
  int regcounto = 0;
  int filecount = 0;
  int stringcount = 0;
  int stringcountn = 0;
  int matchcount = 0;
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
            if (strchr(buff, '\n') == NULL)
              strcat(buff, "\n");
            if (filecount > 0 && stringcount == matchcount && !options->h)
              printf("%s:", argv[i]);
            if (options->n && stringcount == matchcount)
              printf("%d:", stringcountn);
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
