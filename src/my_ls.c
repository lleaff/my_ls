#include <sys/stat.h>
#include <sys/types.h>
#include <sys/unistd.h>
#include "my_ls.h"

t_bool get_files_and_folders(t_ll **files, t_ll **folders,
                         t_ll *filenames, t_opts *opts)
{
  t_stat statbuf;
  t_bool err;
  char *filename;
  t_finfo *finfo_tmp;

  *files = NULL;
  *folders = NULL;
  err = false;
  ll_iter(filenames) {
    filename = (char*)filenames->data;
    if (stat(filename, &statbuf) == -1) {
      err = !file_error(filename);
      continue ;
    }
    finfo_tmp = finfo_new(filename, &statbuf);
    *files = ll_append(*files, ll_new(finfo_tmp));
    if (S_ISDIR(statbuf.st_mode))
      *folders = ll_append(*folders, ll_new(finfo_tmp));
  }
  return (!err);
}

t_bool my_ls(t_ll *args, t_opts *opts)
{
  t_ll *files;
  t_ll *folders;

  if (!get_files_and_folders(&files, &folders, args, opts))
    return (false);
  display_files(files, opts);
  /*
  if (opts->recursive)
    ll_iter(folders)
      my_ls(folders)
      */
  return (true);
}
