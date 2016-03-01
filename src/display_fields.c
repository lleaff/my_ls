#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "my_ls.h"
#include "groups_and_users.h"

#define IS_EXECUTABLE(finfo) ((finfo)->stats.st_mode & S_IXUSR)

void print_filename(t_finfo *finfo)
{
  char *color;
  
  if (finfo->isdir)
    color = FG_BLUE;
  else if (IS_EXECUTABLE(finfo))
    color = FG_MAGENTA;
  else
    color = "";
  my_putstr(color);
  my_putstr(finfo->filename);
  my_putstr(COLOR_RESET" ");
}

void print_permissions(t_finfo *finfo)
{
  mode_t m;

  m = finfo->stats.st_mode;
  my_putchar(S_ISDIR(m) ? 'd' : '-');
  my_putchar(S_IRUSR & m ? 'r' : '-');
  my_putchar(S_IWUSR & m ? 'w' : '-');
  my_putchar(S_IXUSR & m ? 'x' : '-');
  my_putchar(S_IRGRP & m ? 'r' : '-');
  my_putchar(S_IWGRP & m ? 'w' : '-');
  my_putchar(S_IXGRP & m ? 'x' : '-');
  my_putchar(S_IROTH & m ? 'r' : '-');
  my_putchar(S_IWOTH & m ? 'w' : '-');
  my_putchar(S_IXOTH & m ? 'x' : '-');
  my_putchar(' ');
}

void print_links_count(t_finfo *f)
{
  my_put_nbr(f->stats.st_nlink);
  my_putchar(' ');
}

void print_user(t_finfo *finfo, int *colsizes)
{
  my_putstrn(finfo->user, colsizes[COL_USER]);
  my_putchar(' ');
}

void print_group(t_finfo *finfo, int *colsizes)
{
  my_putstrn(finfo->group, colsizes[COL_GROUP]);
  my_putchar(' ');
}
