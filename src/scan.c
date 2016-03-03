#define _GNU_SOURCE /* needed for lstat and readlink with gcc */

#include <sys/stat.h>
#include <sys/types.h>
#include <sys/unistd.h>
#include "my_ls.h"

int get_stats(char *filepath, t_stat *statbuf)
{
  if (g_opts->dereference)
    return (stat(filepath, statbuf));
  else
    return (lstat(filepath, statbuf));
}

void split_files_and_folders(t_ll *entries, t_ll **files, t_ll **folders)
{
  t_finfo *finfo;

  *files = NULL;
  *folders = NULL;
  ll_iter(entries) {
    finfo = (t_finfo*)entries->data;
    if (!g_opts->flat && S_ISDIR(finfo->stats.st_mode))
      *folders = ll_append(*folders, ll_new(finfo));
    else
      *files = ll_append(*files, ll_new(finfo));
  }
}
