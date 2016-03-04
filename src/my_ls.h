#ifndef MY_LS_H
#define MY_LS_H

/* Configuration
 *------------------------------------------------------------*/

/* #define DEBUG */

#define BIN_NAME "my_ls"

#define FCOLOR_EXECUTABLE FG_RED
#define FCOLOR_LINK       FG_MAGENTA
#define FCOLOR_DIR        FG_IBLUE

#define GUTTER_SIZE 2

/* Width used when multi column output is forced outside of a terminal */
#define DEFAULT_OUTPUT_WIDTH 80 

/*------------------------------------------------------------*/

#include <sys/stat.h>
#include <sys/types.h>
typedef struct stat t_stat;

#include "lib.h"
#include "print.h"
#include "args.h"

t_bool columns_too_large(t_ll *lengths, int width);
int get_window_columns();

/* File info
 *------------------------------------------------------------*/
typedef struct s_finfo {
  char   *filename;
  char   *path;
  t_stat stats;
  t_bool isdir;
  t_bool islink;
  char   *link;
  char   *user;
  char   *group;
  int    hardlinks;
  char   *hardlinksstr;
  off_t  size;
  char   *sizestr;
} t_finfo;

t_finfo *finfo_new(char *filename, t_stat *statbuf, char *path);
void finfo_free(t_finfo *finfo);

#define FINFO_LL_FILENAME(f) (((t_finfo*)(f)->data)->filename)

#ifdef DEBUG
void debug_finfo_ll(t_ll *files);
#endif /* DEBUG */

#include "filetype_tests.h"

/*------------------------------------------------------------*/

t_ll *dircontent(char *path);
char get_filetype_char(mode_t m);
char get_filetype_symbol(t_finfo *finfo);

t_bool filter_name(char *name);

/* Display
 *------------------------------------------------------------*/
#define MAX_COL_SIZE 100
#define COL_COUNT 8

#define COL_HARDLINKS 1
#define COL_USER 2
#define COL_GROUP 3
#define COL_SIZE 4

#include "longlist_info.h"
void print_dir_header_maybe(t_bool sngl, t_bool frst, t_bool only_dirs,
                            char *name);
void print_dir_header(char *filename);
void print_filename(t_finfo *f);
t_ll *find_cols(t_ll *files);
void display_files(t_ll *files);
void display_total_blocks(t_ll *files);

t_bool fill_longlist_info(t_ll *files, int *colsizes);
void print_file(t_finfo *finfo);
void print_file_long(t_finfo *finfo, int *colsizes);

t_bool fill_size(t_ll *files, int *colsizes);

void sort_files(t_ll *files);

void print_filename(t_finfo *f);
void print_permissions(t_finfo *f);
void print_links_count(t_finfo *f, int *colsizes);
void print_user(t_finfo *finfo, int *colsizes);
void print_group(t_finfo *finfo, int *colsizes);
void print_filesize(t_finfo *finfo, int *colsizes);
void print_time(time_t t);
void print_mod_date(t_finfo *finfo);
void print_link_info(t_finfo *finfo);

void print_files_cols(t_ll *files);
void print_files_long(t_ll* files);
void print_files_stream(t_ll *files);
void print_filenames_nocols(t_ll *files);

/*------------------------------------------------------------*/

t_bool parse_args(t_ll **o_args, t_opts **o_opts, int argc, char **argv);
t_bool my_ls(t_ll *args, char *path);

void free_entries(t_ll *entries, t_ll *files, t_ll *folders);

#define zeroify(ptr) do { my_memset(ptr, 0, sizeof(*ptr)); } while (0)

#endif /* MY_LS_H */
