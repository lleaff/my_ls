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

void display_files(t_ll *files)
{
  if (files == NULL)
      return ;

  if (g_opts->longlist)
      print_files_long(files);
  else if (g_opts->streamformat)
      print_files_stream(files);
  else
      print_files_cols(files);
}
