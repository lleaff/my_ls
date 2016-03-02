#include <stdlib.h>
#include "linkedlist.h"
#include "lib.h"

void ll_debug_strings(t_ll* node)
{
  my_putstr("DEBUG(t_ll*) {\n\"");
  ll_print_strings(node, "\",\n\"");
  my_putstr("\"\n}\n");
}

void ll_debug_ints(t_ll* node)
{
  my_putstr("DEBUG(t_ll*) {\n");
  for (; node != NULL; node = node->next)
  {
    my_put_nbr(*(int*)node->data);
    if (node->next != NULL)
      my_putstr(", ");
  }
  my_putstr("\n}\n");
}
