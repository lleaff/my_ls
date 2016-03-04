#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "my_ls.h"

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

void print_filenames_nocols(t_ll *files)
{
    ll_iter(files)
    {
        print_filename(files->data);
        my_putchar('\n');
    }
}

void print_filename_cols(t_finfo *finfo, int colsize)
{
  print_filename(finfo);
  if (colsize)
    my_putstrn("", colsize - my_strlen(finfo->filename) - g_opts->filetypesymb);
  else
    my_putchar('\n');
}

static void _print_files_cols_loop(t_ll *files, t_ll *cols)
{
    int i;
    int c;

    c = ll_length(cols);
    for (i = 0; files != NULL; files = files->next)
    {
        print_filename_cols(files->data, c ? COLSIZE_AT(i) : 0);
        if (i >= c - 1)
        {
            i = 0;
            my_putchar(files->next != NULL ? '\n' : '\0');
        }
        else
        {
            print_gutter();
            i++;
        }
    }
    my_putchar('\n');
    ll_free(cols);
}

void print_files_cols(t_ll *files)
{
  t_ll *cols;

  if (g_opts->oneentperline)
  {
      print_filenames_nocols(files);
      return ;
  }
  cols = find_cols(files);
  if (cols == NULL)
  {
      print_filenames_nocols(files);
      return ;
  }
  _print_files_cols_loop(files, cols);
}
