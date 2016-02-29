#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "my_ls.h"
#include "groups_and_users.h"

void display_files(t_ll *files, t_opts *opts)
{
  t_finfo* finfo;
  ll_iter(files) {
    finfo = (t_finfo*)files->data;
    print_filename(finfo);
    my_putstr("\n");
    print_permissions(finfo->stats.st_mode);
  }
}
