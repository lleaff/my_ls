#ifndef ARGS_H
#define ARGS_H

#include "lib.h"

#define USAGE "USAGE: "BIN_NAME" [OPTION]... [FILE]...\n\n\
OPTIONS:\n\
  -l\t Long list format.\n\
  -R\t Recursive.\n\
  -r\t Reverse sort order.\n\
  -d\t Don't follow links given as arguments.\n\
  -t\t Sort by modification time.\n\
  -a\t Include hidden files.\n\
  -A\t Include hidden files except '.' and '..'.\n\
  -L\t Dereference symbolic links.\n\
  -G\t Colorize output.\n\
  -g\t Print group name (long list format without owner name).\n\
  -f\t Don't sort output. This option turns on the -a option.\n\
  --help Print help\n\
"

#define OPTION_LIST "lRrdtaALGgf"

typedef struct s_opts {
    t_bool longlist;      /* -l */
    t_bool recursive;     /* -R */
    t_bool reverse;       /* -r */
    t_bool flat;          /* -d */
    t_bool sortmodtime;   /* -t */
    t_bool all;           /* -a */
    t_bool almostall;     /* -A */
    t_bool dereference;   /* -L */
    t_bool colorize;      /* -G */
    t_bool longlistgroup; /* -g */
    t_bool nosort;        /* -f */
} t_opts;

extern t_opts *g_opts;

#endif /* ARGS_H */
