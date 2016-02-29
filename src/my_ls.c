#include <sys/stat.h>
#include <sys/types.h>
#include <sys/unistd.h>
#include "my_ls.h"

t_ll *get_files_and_folders(t_ll *filenames, t_opts *opts)
{
  t_stat statbuf;
  t_bool err;
  char *filename;
  t_finfo *finfo_tmp;
  t_ll *files;

  files = NULL;
  err = false;
  ll_iter(filenames) {
    filename = (char*)filenames->data;
    if (stat(filename, &statbuf) == -1) {
      err = !file_error(filename);
      continue ;
    }
    finfo_tmp = finfo_new(filename, &statbuf);
    files = ll_append(files, ll_new(finfo_tmp));
  }
  sort_files(files, opts);
  return (!err ? files : NULL);
}

t_ll *only_folders(t_ll *files, t_opts *opts)
{
  t_ll *folders;
  t_finfo *finfo;

  finfo = (t_finfo*)files->data;
  noop(opts);/* DEBUG */
  folders = NULL;
  ll_iter(files) {
    if (S_ISDIR(finfo->stats.st_mode))
      folders = ll_append(folders, ll_new(finfo));
  }
  return (folders);
}

t_bool my_ls(t_ll *args, t_opts *opts)
{
  t_ll *files;
  t_ll *folders;

  if ((files = get_files_and_folders(args, opts)) == NULL)
    return (false);
  folders = only_folders(files, opts);
  display_files(files, opts);
  noop(folders);/* DEBUG */
  /*
  if (opts->recursive)
    ll_iter(folders)
      my_ls(folders)
      */
  return (true);
}
