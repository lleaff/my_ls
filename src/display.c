#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "my_ls.h"

void display_files(t_ll *files, t_opts *opts)
{
  t_finfo* finfo;
  int colsizes[COL_COUNT];

  sort_files(files, opts);
  if (opts->longlist)
    fill_longlist_info(files, colsizes);

  ll_iter(files) {
    finfo = (t_finfo*)files->data;
    if (opts->longlist)
      print_file_long(finfo, colsizes);
    else
      print_file(finfo);
  }
}
