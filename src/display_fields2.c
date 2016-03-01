#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include "my_ls.h"
#include "groups_and_users.h"

void print_filesize(t_finfo *finfo, int *colsizes)
{
  my_putstrnr(finfo->sizestr, colsizes[COL_SIZE]);
  my_putchar(' ');
}

void print_mod_date(t_finfo *finfo)
{
  time_t t;

  t = finfo->stats.st_mtime;
  print_time(t);
  my_putchar(' ');
}
