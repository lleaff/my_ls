#include <stdlib.h>
#include "my_ls.h"

static void *lladdlenghts(void *acc, t_ll *node)
{
  int *x;
  
  x = malloc(sizeof(*x));
  *x = (*(int*)acc + *(int*)node->data +
        (node->next != NULL ? GUTTER_SIZE : 0));
  return (x);
}

t_bool columns_too_large(t_ll *lengths, int width)
{
  int full_length;
  int fold_start;

  fold_start = 0;
  full_length = *(int*)ll_foldr(lengths, lladdlenghts, &fold_start);

  return (full_length > width);
}
