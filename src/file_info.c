#include "my_ls.h"

t_finfo *finfo_new(char *filename, t_stat *statbuf)
{
  t_finfo *info;

  if ((info = malloc(sizeof(*info))) == NULL)
    return (fail_ptr("f_new: malloc failed.\n"));

  info->filename = filename;
  info->stats = *statbuf;
  info->isdir = S_ISDIR(statbuf->st_mode);
  return (info);
}
