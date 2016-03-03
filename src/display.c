#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "my_ls.h"

void print_dir_header_maybe(t_bool single_dir, t_bool first,
                            t_bool only_dirs, char *name)
{
  if (single_dir && !g_opts->recursive)
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

void print_filenames_nocols(t_ll *files)
{
    ll_iter(files)
    {
        print_filename(files->data);
        if (files->next != NULL)
            print_gutter();
    }
}

void print_filename_cols(t_finfo *finfo, int colsize)
{
  print_filename(finfo);
  if (colsize)
    my_putstrn("", colsize - my_strlen(finfo->filename));
  else
    my_putchar('\n');
}

void print_files_cols(t_ll *files)
{
  t_ll *cols; int c;
  int i;

  cols = find_cols(files);
  if (cols == NULL)
  {
      print_filenames_nocols(files);
      return ;
  }
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

void display_files(t_ll *files)
{
  if (files == NULL)
    return ;

  if (g_opts->longlist)
    print_files_long(files);
  else
    print_files_cols(files);
}
