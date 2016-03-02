#include <stdlib.h>
#include "my_ls.h"

static void _finfo_free_foreach(void *data, t_ll *node, int i)
{
  finfo_free((t_finfo*)data);
  free(data);
  noop(node);
  noop(&i);
}

void free_entries(t_ll *entries, t_ll *files, t_ll *folders)
{
  ll_free_nodata(files);
  ll_free_nodata(folders);
  ll_foreach(entries, _finfo_free_foreach);
  ll_free_nodata(entries);
}
