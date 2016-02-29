#ifndef MY_LS_H
#define MY_LS_H

#define DEBUG

#define BIN_NAME "my_ls"

#include "lib.h"
#include "print.h"
#include "args.h"

t_bool parse_args(t_ll **o_args, t_opts **o_opts, int argc, char **argv);
t_bool my_ls(t_ll *args, t_opts *opts);

#endif /* MY_LS_H */
