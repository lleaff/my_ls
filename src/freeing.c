#include <stdlib.h>
#include "my_ls.h"

void free_entries(t_ll *entries, t_ll *files, t_ll *folders)
{
  ll_free_nodata(files);
  ll_free_nodata(folders);
  ll_free(entries);
}
