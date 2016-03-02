#include <stdlib.h>
#include "linkedlist.h"
#include "lib.h"

void ll_print_strings(t_ll* node, char *delim)
{
    for (; node != NULL; node = node->next)
    {
        my_putstr(node->data);
        if (node->next != NULL)
            my_putstr(delim);
    }
}

void ll_sort(t_ll *node, t_comparison_fn cmp)
{
  t_ll *min;
  t_ll *j;

  if (node == NULL)
    return ;
  for (min = node; node->next != NULL; node = node->next, min = node)
  {
    for (j = node->next; j != NULL; j = j->next)
      if (cmp(min->data, j->data) > 0)
        min = j;
    if (min != node)
      ll_swap(min, node);
  }
}

int ll_length_gt(t_ll *node, int n)
{
  int l;

  for (l = 0; node != NULL; node = node->next)
  {
    l++;
    if (l > n)
      return (1);
  }
  return (0);
}
