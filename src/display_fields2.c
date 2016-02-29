#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "my_ls.h"
#include "groups_and_users.h"

void print_filesize(t_finfo *finfo, int *colsizes)
{
  my_putstrn(finfo->sizestr, colsizes[COL_SIZE]);
  my_putchar(' ');
}

void print_mod_date(t_finfo *finfo)
{
  /* TODO */
}
