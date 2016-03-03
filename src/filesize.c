#include "my_ls.h"

t_bool fill_size(t_ll *files, int *colsizes)
{
  int max_size_len;
  int len;
  t_finfo *finfo;

  max_size_len = 0;
  ll_iter(files) {
    finfo = (t_finfo*)files->data;
    finfo->size = finfo->stats.st_size;
    finfo->sizestr = g_opts->humanreadable ?
      size_to_human_readable(finfo->size) : my_longlongtoa(finfo->size);
    len = my_strlen(finfo->sizestr);
    max_size_len = MAX(max_size_len, len);
  }
  colsizes[COL_SIZE] = max_size_len;
  return (true);
}
