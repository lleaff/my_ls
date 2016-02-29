#ifndef ARGS_H
#define ARGS_H

#include "lib.h"

#define OPTION_LIST "lRrdtaAL"

typedef struct s_opts {
    t_bool longlist;      /* -l */
    t_bool recursive;     /* -R */
    t_bool reverse;      /* -r */
    t_bool flat;          /* -d */
    t_bool sortmodtime;   /* -t */
    t_bool all;           /* -a */
    t_bool almostall;     /* -A */
    t_bool dereference;   /* -L */
} t_opts;

#endif /* ARGS_H */
