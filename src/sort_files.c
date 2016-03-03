#include "my_ls.h"

#define difftime(a, b) ((a) - (b))

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
  return (-1 * difftime(((t_finfo*)a)->stats.st_mtime,
                   ((t_finfo*)b)->stats.st_mtime));
}

int finfo_cmp_modtimes_reverse(const void *a, const void *b)
{
  return (finfo_cmp_modtimes(a, b) * -1);
}

void sort_files(t_ll *files)
{
  int (*cmp)(const void*, const void*);

  if (g_opts->nosort)
      return ;
  if (g_opts->sortmodtime)
    cmp = g_opts->reverse ? finfo_cmp_modtimes_reverse : finfo_cmp_modtimes;
  else
    cmp = g_opts->reverse ? finfo_cmp_names_reverse : finfo_cmp_names;

  ll_sort(files, cmp);
}
