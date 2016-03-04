#include <stdlib.h>
#include "my_ls.h"

static t_ll *init_cols(int c)
{
  const int zero = 0;

  return ll_new_data_n((void*)&zero, sizeof(zero), c);
}

static void *llstrlen(t_ll *node)
{
  int *x;

  x = malloc(sizeof(*x));
  *x = my_strlen(FINFO_LL_FILENAME(node));
  return (x);
}

t_bool one_liner(t_ll *files, int width, t_ll **cols)
{
  t_ll *lengths;

  lengths = ll_map(files, llstrlen);
  if (columns_too_large(lengths, width))
    return (false);
  *cols = lengths;
  return (true);
}

#define COLSIZE_AT(x) (*(int*)(ll_nth(cols, (x) % c)->data))

static t_ll *find_cols_rec(t_ll *files, int c, int width)
{
  t_ll *cols;
  t_ll *more_cols;
  t_ll *file;
  int i;
  int max;
  int len;

  cols = init_cols(c);
  for (i = 0, file = files; file != NULL; i++, file = file->next)
  {
    max = COLSIZE_AT(i);
    len = my_strlen(FINFO_LL_FILENAME(file)) + g_opts->filetypesymb;
    if (len > max)
    {
      COLSIZE_AT(i) = len;
    }
  }
  
  if (columns_too_large(cols, width))
  {
    ll_free(cols);
    return (NULL);
  }
  more_cols = find_cols_rec(files, c + 1, width);
  return (more_cols != NULL) ? more_cols : cols;
}

t_ll *find_cols(t_ll *files)
{
  t_ll *cols;
  int term_cols;

  term_cols = get_window_columns();
  if (term_cols == -1)
  {
      if (g_opts->multicolumn)
          term_cols = DEFAULT_OUTPUT_WIDTH;
      else
          return (NULL);
  }

  if (one_liner(files, term_cols, &cols))
    return (cols);
  cols = find_cols_rec(files, 2, term_cols);
  return (cols);
}
