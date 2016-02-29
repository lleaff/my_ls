#include <time.h>
#include "my_ls.h"

int finfo_cmp_names(const void *a, const void *b)
{
  return (my_strcmp(((t_finfo*)a)->filename,
                    ((t_finfo*)b)->filename));
}

int finfo_cmp_names_reverse(const void *a, const void *b)
{
  return (finfo_cmp_names(a, b) * -1);
}

int finfo_cmp_modtimes(const void *a, const void *b)
{
  return (difftime(((t_finfo*)a)->stats.st_mtime,
                   ((t_finfo*)b)->stats.st_mtime));
}

int finfo_cmp_modtimes_reverse(const void *a, const void *b)
{
  return (finfo_cmp_modtimes(a, b) * -1);
}

void sort_files(t_ll *files, t_opts *opts)
{
  int (*cmp)(const void*, const void*);

  if (opts->sortmodtime)
    cmp = opts->reverse ? finfo_cmp_modtimes_reverse : finfo_cmp_modtimes;
  else
    cmp = opts->reverse ? finfo_cmp_names_reverse : finfo_cmp_names;

  ll_sort(files, cmp);
}
