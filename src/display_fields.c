#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "my_ls.h"
#include "groups_and_users.h"

void print_filename(t_finfo *f)
{
  my_putstr(f->isdir ? FG_BLUE : "");
  my_putstr(f->filename);
  my_putstr(COLOR_RESET" ");
}

void print_permissions(mode_t m)
{
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

void print_links_count(int n)
{
  my_put_nbr(n);
  my_putchar(' ');
}
