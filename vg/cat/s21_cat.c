#include "names.h"
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

void parcer(int argc, char *argv[], opt *options);
void reader(char *argv[], opt *options);

int main(int argc, char *argv[]) {
  opt options;
  parcer(argc, argv, &options);
  if (options.b == 1) {
    options.n = 0;
  }
  reader(argv, &options);
  return 0;
}

void parcer(int argc, char *argv[], opt *options) {
  int opt = 0;
  static struct option long_options[] = {
      {"number-nonblank", no_argument, 0, 'b'},
      {"E", no_argument, 0, 'e'},
      {"E", no_argument, 0, 'T'},
      {"number", no_argument, 0, 'n'},
      {"squeezee-blank", no_argument, 0, 's'},
      {"T", no_argument, 0, 't'},
      {0, 0, 0, 0}};
  int long_ingex = 0;
  while ((opt = getopt_long(argc, argv, "+benstvTE:", long_options,
                            &long_ingex)) != -1) {
    switch (opt) {
    case 's':
      options->s = 1;
      break;
    case 'b':
      options->b = 1;
      break;
    case 'e':
      options->e = 1;
      options->v = 1;
      break;
    case 'n':
      options->n = 1;
      break;
    case 't':
      options->t = 1;
      options->v = 1;
      break;
    case 'v':
      options->v = 1;
      break;
    default:
      exit(1);
    }
    if (options->b == 1 && options->n == 1)
      options->n = 0;
  }
}

void reader(char *argv[], opt *options) {
  FILE *f;
  char cur = 0;
  int str_count = 0;
  int pstr = -1;
  int ppstr = -1;
  int g = 0;
  if ((f = fopen(argv[optind], "r")) != NULL) {
    while ((f = fopen(argv[optind++], "r")) != NULL) {
      while ((cur = fgetc(f)) != EOF) {
        if (options->b == 1 && (ppstr != '\n' || ppstr != -1) &&
            (pstr == '\n' || g == 0) && (cur != '\n' || cur == 0)) {
          g = 1;
          printf("%6d\t", ++str_count);
        }
        if (options->s == 1 && (ppstr == '\n' || ppstr == -1) && pstr == '\n' &&
            cur == '\n') {
          ppstr = pstr;
          pstr = cur;
          continue;
        }
        if (options->n == 1 &&
            ((ppstr != '\n' || ppstr != -1) && (pstr == '\n' || g == 0) &&
             (cur != '\n' || cur != 0))) {
          g = 1;
          printf("%6d\t", ++str_count);
        }
        ppstr = pstr;
        pstr = cur;
        if (options->t == 1 && cur == '\t') {
          printf("^I");
          continue;
        }
        if (options->v == 1) {
          if (cur <= 31 && cur != 10 && cur != 9) {
            printf("^");
            cur += 64;
          } else if (cur == 127) {
            printf("^");
            cur -= 64;
          }
        }
        if (options->e == 1 && cur == '\n') {
          printf("$\n");
        } else {
          printf("%c", cur);
        }
      }
      str_count = 0;
      g = 0;
    }
  } else {
    fprintf(stderr, "\ncat: %s: No such file or directory\n", argv[optind]);
  }
  fclose(f);
}
