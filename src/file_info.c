#define _GNU_SOURCE /* needed for lstat and readlink with gcc */

#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "my_ls.h"

#define PATH_BUFFER_LENGTH 250

char *link_destination(char *filepath)
{
  size_t path_size;
  char path_buffer[PATH_BUFFER_LENGTH];

  path_size = readlink(filepath, path_buffer, PATH_BUFFER_LENGTH);
  return (my_strnnew(path_buffer, path_size));
}

t_finfo *finfo_new(char *filename, t_stat *statbuf, char *path)
{
  t_finfo *info;
  t_bool is_link;

  if ((info = malloc(sizeof(*info))) == NULL)
    return (fail_ptr("f_new: malloc failed.\n"));

  info->filename = filename;
  info->stats = *statbuf;
  info->path = path;
  info->isdir  = S_ISDIR(info->stats.st_mode);

  is_link = S_ISLNK(info->stats.st_mode);
  info->islink = is_link;
  if (is_link)
    info->link = link_destination(concat_paths(path, filename));
  return (info);
}

void debug_finfo_ll(t_ll *files)
{
  my_putstr("DEBUG: files {\n");
  for (; files != NULL; files = files->next)
  {
    print_filename((t_finfo*)files->data);
    my_putstr(files->next != NULL ? ", " : "");
  }
  my_putstr("\n}\n");
}
