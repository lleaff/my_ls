#include <sys/stat.h>
#include <sys/types.h>
#include <sys/unistd.h>
#include "my_ls.h"

t_bool g_first = true;
int infinite_recursion_guard = 0;  /* DEBUG */

t_ll *get_files_and_folders(t_ll *filenames, char *path, t_opts *opts)
{
  t_stat statbuf;
  t_bool err;
  char *filename;
  char *filepath;
  t_finfo *finfo_tmp;
  t_ll *files;

  files = NULL;
  err = false;
  ll_iter(filenames) {
    filename = (char*)filenames->data;
    filepath = concat_paths(path, filename);
    if (stat(filepath, &statbuf) == -1) {
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

  noop(opts);/* DEBUG */
  folders = NULL;
  ll_iter(files) {
    finfo = (t_finfo*)files->data;
    if (S_ISDIR(finfo->stats.st_mode))
      folders = ll_append(folders, ll_new(finfo));
  }
  return (folders);
}

t_bool my_ls(t_ll *filenames, char *path, t_opts *opts)
{
  t_ll *files;
  t_ll *folders;
  t_finfo *finfo;
  char *new_folder;
  

  /*
  my_putstr("FILENAMES: ");
  ll_debug_strings(filenames);
  my_putstr("_____________________________\n");
  */

  if ((files = get_files_and_folders(filenames, path, opts)) == NULL)
    return (false);
  folders = only_folders(files, opts);
  display_files(files, opts);
  if (opts->recursive)
  {
    ll_iter(folders) {
      finfo = (t_finfo*)folders->data;
      new_folder = concat_paths(path, finfo->filename);
      if ((filenames = dircontent(new_folder, opts)) == NULL)
        return (false);
      print_dir_header(new_folder);
      my_ls(filenames, new_folder, opts);
    }
  }
  return (true);
}
