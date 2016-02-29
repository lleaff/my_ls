#include <sys/stat.h>
#include <sys/types.h>
#include <sys/unistd.h>
#include "my_ls.h"

#define for_loop(start, end, incr) for(i = start; \
                                        i < end;  \
                                         i += incr)

typedef struct stat t_stat;

t_bool get_files_and_folders(t_ll **files, t_ll **folders,
                         t_ll *args, t_opts *opts)
{
  *files = NULL;
  *folders = NULL;
  t_stat statbuf;
  t_bool err;

  err = false;
  ll_iter(args) {
    if (stat((char*)args->data, &statbuf) == -1) {
      err = !file_error((char*)args->data);
      continue ;
    }
    ll_append(*(S_ISDIR(statbuf.st_mode) ? folders : files),
              ll_new_data(&statbuf, sizeof(statbuf)));
  }
  return (!err);
}

t_bool my_ls(t_ll *args, t_opts *opts)
{
  t_ll *files;
  t_ll *folders;

  if (!get_files_and_folders(&files, &folders, args, opts))
    return (false);
  return (true);
}
