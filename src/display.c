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

void print_permission(mode_t m)
{

  printf("S_IRUSR: %d\n", S_IRUSR);
  printf("S_IWUSR: %d\n", S_IWUSR);
  printf("S_IXUSR: %d\n", S_IXUSR);
  printf("S_IRGRP: %d\n", S_IRGRP);
  printf("S_IWGRP: %d\n", S_IWGRP);
  printf("S_IXGRP: %d\n", S_IXGRP);
  printf("S_IROTH: %d\n", S_IROTH);
  printf("S_IWOTH: %d\n", S_IWOTH);
  printf("S_IXOTH: %d\n", S_IXOTH);


  /*
  my_putchar(S_ISDIR(m) ? 'd' : '-');
  my_putchar(S_IRUSR(m) ? 'r' : '-');
  my_putchar(S_IWUSR(m) ? 'w' : '-');
  my_putchar(S_IXUSR(m) ? 'x' : '-');
  my_putchar(S_IRGRP(m) ? 'r' : '-');
  my_putchar(S_IWGRP(m) ? 'w' : '-');
  my_putchar(S_IXGRP(m) ? 'x' : '-');
  my_putchar(S_IROTH(m) ? 'r' : '-');
  my_putchar(S_IWOTH(m) ? 'w' : '-');
  my_putchar(S_IXOTH(m) ? 'x' : '-');
  my_putchar(' ');
  */
}

void print_links_count(int n)
{
  my_put_nbr(n);
  my_putchar(' ');
}

void display_files(t_ll *files, t_opts *opts)
{
  /*
  int max_group_l;
  int max_user_l;
  */
  ll_iter(files) {
    print_filename((t_finfo*)files->data);
  }
}
