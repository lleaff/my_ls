#include "my_ls.h"

t_finfo *finfo_new(char *filename, t_stat *statbuf)
{
  t_finfo *info;

  if ((info = malloc(sizeof(*info))) == NULL)
    return (fail_ptr("f_new: malloc failed.\n"));

  info->filename = filename;
  info->stats = *statbuf;
  info->isdir = S_ISDIR(info->stats.st_mode);
  return (info);
}

void debug_finfo_ll(t_ll *files)
{
  my_putstr("DEBUG: files {\n");
  for (; files != NULL; files = files->next)
  {
    print_filename((t_finfo*)files->data);
    my_putstr(files->next != NULL ? ", " : "");
  }
  my_putstr("\n}\n");
}
