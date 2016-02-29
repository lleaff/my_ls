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

void ll_debug_strings(t_ll* node)
{
    my_putstr("DEBUG(t_ll*) {\n\"");
    ll_print_strings(node, "\",\n\"");
    my_putstr("\"\n}\n");
}

void   ll_sort(t_ll *node, t_comparison_fn cmp)
{
  t_ll *min;
  t_ll *j;

  for (min = node; node->next != NULL; node = node->next, min = node)
  {
    for (j = node->next; j != NULL; j = j->next)
      if (cmp(min->data, j->data) > 0)
        min = j;
    if (min != node)
      ll_swap(min, node);
  }
}
