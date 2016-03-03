#include <time.h>
#include "my_ls.h"
#include "longlist_info.h"

void print_filesize(t_finfo *finfo, int *colsizes)
{
  char *str;
  if (g_opts->humanreadable)
    str = size_to_human_readable(finfo->size);
  else
    str = finfo->sizestr;
  my_putstrnr(str, colsizes[COL_SIZE]);
  my_putchar(' ');
  if (g_opts->humanreadable)
    free(str);
}

void print_mod_date(t_finfo *finfo)
{
  time_t t;

  t = finfo->stats.st_mtime;
  print_time(t);
  my_putchar(' ');
}

void print_link_info(t_finfo *finfo)
{
  if (!finfo->islink)
    return ;
  my_putstr(" -> ");
  my_putstr(finfo->link);
}
