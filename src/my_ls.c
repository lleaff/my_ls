#define _GNU_SOURCE /* needed for lstat and readlink with gcc */

#include <sys/stat.h>
#include <sys/types.h>
#include <sys/unistd.h>
#include "my_ls.h"

t_bool g_first = true;

int get_stats(char *filepath, t_stat *statbuf);
void split_files_and_folders(t_ll *entries, t_ll **files, t_ll **folders);

char *build_path(char *path, char *filename)
{
    if (g_first && !path_is_current(path))
        return (filename);
    else
        return (concat_paths(path, filename));
}

t_ll *get_fileinfos(t_ll *filenames, char *path)
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
    filenames = ll_new(my_strnew("."));
  ll_iter(filenames) {
    filename = (char*)filenames->data;
    filepath = build_path(path, filename);
    if (get_stats(filepath, &statbuf) == -1) 
      err = !file_error(filename);
    else
    {
        finfo_tmp = finfo_new(filename, &statbuf, path);
        files = ll_append(files, ll_new(finfo_tmp));
    }
  }
  sort_files(files);
  return (!err ? files : NULL);
}

/*------------------------------------------------------------*/

#define ONLY_DIRS(files) ((files) == NULL)

t_bool scan_folder(t_finfo *folder, char *path,
        t_bool single_dir, t_bool only_dirs)
{
    char *new_folder;
    t_ll *content;

    if (!g_first && path_is_dot_ref(folder->filename))
        return (false);
    new_folder = g_first ? folder->filename :
        concat_paths(path, folder->filename);
    if ((content = dircontent(new_folder)) == NULL)
        return (false);
    print_dir_header_maybe(single_dir, g_first, only_dirs, new_folder);
    g_first = false;
    my_ls(content, new_folder);
    return (true);
}

t_bool scan_folders(t_ll *files, t_ll *folders, char *path,
                   t_bool single_dir)
{
  t_bool only_dirs;

  only_dirs = ONLY_DIRS(files);
  if (g_first || g_opts->recursive)
  {
    ll_iter(folders) {
      scan_folder(folders->data, path, single_dir, only_dirs);
    }
  }
  return (true);
}

#define SINGLE_DIR(filenames, first) \
  ((!ll_length_gt(filenames, 1)) && first)

t_bool my_ls(t_ll *filenames, char *path)
{
  t_ll *entries;
  t_ll *files;
  t_ll *folders;
  t_bool single_dir;

  single_dir = SINGLE_DIR(filenames, g_first);
  if ((entries = get_fileinfos(filenames, path)) == NULL)
    return (false);
  if (g_opts->longlist && !g_first)
      display_total_blocks(entries);
  split_files_and_folders(entries, &files, &folders);
  if (!single_dir)
    display_files(g_first ? files : entries);
  if (!scan_folders(files, folders, path, single_dir))
    return (false);
  free_entries(entries, files, folders);
  return (true);
}
