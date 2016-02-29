#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "my_ls.h"
#include "groups_and_users.h"

void display_files(t_ll *files, t_opts *opts)
{
  t_finfo* finfo;
  int colsizes[COL_COUNT];
  if (opts->longlist)
    fill_user_and_group(files, colsizes);

  ll_iter(files) {
    finfo = (t_finfo*)files->data;
    print_permissions(finfo);
    print_links_count(finfo);
    print_user(finfo, colsizes);
    print_group(finfo, colsizes);

    print_filename(finfo);
    my_putchar('\n');
  }
}
