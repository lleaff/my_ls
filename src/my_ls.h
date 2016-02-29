#ifndef MY_LS_H
#define MY_LS_H

#define DEBUG

#define BIN_NAME "my_ls"
#include <sys/stat.h>
#include <sys/types.h>
typedef struct stat t_stat;

#include "lib.h"
#include "print.h"
#include "args.h"

typedef struct s_finfo {
  char *filename;
  t_stat stats;
  t_bool isdir;
  char *user;
  char *group;
} t_finfo;

t_finfo *finfo_new(char *filename, t_stat *statbuf);

/* Display
 *------------------------------------------------------------*/
#include "groups_and_users.h"
void print_filename(t_finfo *f);
void display_files(t_ll *files, t_opts *opts);

#define MAX_COL_SIZE 100
#define COL_COUNT 8
#define COL_USER 2
#define COL_GROUP 3

void print_filename(t_finfo *f);
void print_permissions(t_finfo *f);
void print_links_count(t_finfo *f);
void print_user(t_finfo *finfo, int *colsizes);
void print_group(t_finfo *finfo, int *colsizes);

/*------------------------------------------------------------*/

t_bool parse_args(t_ll **o_args, t_opts **o_opts, int argc, char **argv);
t_bool my_ls(t_ll *args, t_opts *opts);

#endif /* MY_LS_H */
