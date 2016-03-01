#include <sys/stat.h>
#include <sys/types.h>
#include <sys/unistd.h>
#include "my_ls.h"

t_bool g_first = true;

#ifdef DEBUG
int infinite_recursion_guard = 0;  /* DEBUG */
#endif

t_ll *get_fileinfos(t_ll *filenames, char *path, t_opts *opts)
{
  t_stat statbuf;
  t_bool err;
  char *filename;
  char *filepath;
  t_finfo *finfo_tmp;
  t_ll *files;

  files = NULL;
  err = false;
  if (filenames == NULL)
    filenames = ll_new(".");
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

void split_files_and_folders(t_ll *entries, t_opts *opts,
                             t_ll **files, t_ll **folders)
{
  t_finfo *finfo;

  noop(opts);/* DEBUG */
  *files = NULL;
  *folders = NULL;
  ll_iter(entries) {
    finfo = (t_finfo*)entries->data;
    if (!opts->flat && S_ISDIR(finfo->stats.st_mode))
      *folders = ll_append(*folders, ll_new(finfo));
    else
      *files = ll_append(*files, ll_new(finfo));
  }
}

/*------------------------------------------------------------*/

t_bool scan_folder(t_ll *files, t_ll *folders, char *path,
                   t_opts *opts, t_bool single_dir)
{
  t_finfo *finfo;
  char *new_folder;
  t_ll *content;

  if (g_first || opts->recursive)
  {
    ll_iter(folders) {
      finfo = (t_finfo*)folders->data;
      new_folder = concat_paths(path, finfo->filename);
      if ((content = dircontent(new_folder, opts)) == NULL)
        return (false);
      print_dir_header_maybe(single_dir, opts, new_folder);
      g_first = false;
      my_ls(content, new_folder, opts);
    }
  }
  return (true);
}

#define SINGLE_DIR(filenames, first) \
  ((!ll_length_gt(filenames, 1)) && first)

t_bool my_ls(t_ll *filenames, char *path, t_opts *opts)
{
  t_ll *entries;
  t_ll *files;
  t_ll *folders;
  t_bool single_dir;

#ifdef DEBUG
  if (++infinite_recursion_guard > 10) { printf("GUARD\n"); return false; }
#endif
  single_dir = SINGLE_DIR(filenames, g_first);
  if ((entries = get_fileinfos(filenames, path, opts)) == NULL)
    return (false);
    split_files_and_folders(entries, opts, &files, &folders);
  if (!single_dir)
    display_files(entries, opts);
  if (!scan_folder(files, folders, path, opts, single_dir))
    return (false);
  return (true);
}
