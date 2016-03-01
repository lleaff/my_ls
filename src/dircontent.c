#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include "my_ls.h"

typedef struct dirent t_dirent;

t_bool filter_name(char *name, t_opts *opts)
{
  if (!(opts->all || opts->almostall) && name[0] == '.')
    return (false);
  if (opts->almostall && (!my_strcmp(name, ".") || !my_strcmp(name, "..")))
    return (false);
  return (true);
}

t_ll *dircontent(t_finfo *finfo, t_opts *opts)
{
  DIR *dir;
  t_ll *filenames;
  char *name;
  t_dirent *ent;

  if ((dir = opendir(finfo->filename)) == NULL)
    return (file_error_ptr(finfo->filename));
  filenames = NULL;
  for(ent = readdir(dir); ent != NULL; ent = readdir(dir))
  {
    name = ent->d_name;
    if (!filter_name(name, opts))
      continue ;
    filenames = ll_append(filenames, ll_new_data(name, my_strlen(name) + 1));
  }
  return (filenames);
}
