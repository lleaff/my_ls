#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "my_ls.h"

void print_dir_header_maybe(t_bool single_dir, t_bool first,
                            t_bool only_dirs, t_opts *opts, char *name)
{
  if (single_dir && !opts->recursive)
    return ;
  if (!(first && only_dirs))
    my_putchar('\n');
  print_dir_header(name);
}

void print_dir_header(char *filename)
{
  my_putstr(filename);
  my_putstr(":\n");
}

void print_files_long(t_ll* files)
{
  int colsizes[COL_COUNT];
  t_finfo *finfo;

  fill_longlist_info(files, colsizes);
  ll_iter(files) {
    finfo = (t_finfo*)files->data;
      print_file_long(finfo, colsizes);
  }
}

#define COLSIZE_AT(x) (*(int*)(ll_nth(cols, (x) % c)->data))

void print_files_cols(t_ll *files)
{
  t_ll *cols;
  int c;
  int i;

  cols = find_cols(files);
  c = ll_length(cols);
  for (i = 0; files != NULL; files = files->next)
  {
    my_putstrn(FINFO_LL_FILENAME(files), COLSIZE_AT(i));
    if (i >= c - 1)
    {
      i = 0;
      my_putchar('\n');
    }
    else
    {
      print_gutter();
      i++;
    }
  }
  
  my_putchar('\n');
}

void display_files(t_ll *files, t_opts *opts)
{
  if (files == NULL)
    return ;

  if (opts->longlist)
    print_files_long(files);
  else
    print_files_cols(files);
}
