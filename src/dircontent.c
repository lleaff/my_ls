#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include "my_ls.h"

typedef struct dirent t_dirent;

t_ll *dircontent(char *path, t_opts *opts)
{
  DIR *dir;
  t_ll *filenames;
  char *name;
  t_dirent *ent;

  if ((dir = opendir(path)) == NULL)
    return (file_error_ptr(path));
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
