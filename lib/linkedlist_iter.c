#include "linkedlist.h"

t_ll*  ll_map(t_ll *node, void*(f)(t_ll* node))
{
  t_ll *new_n;

  if (node == NULL)
    return (NULL);
  new_n = ll_new(f(node));
  new_n->next = ll_map(node->next, f);
  return (new_n);
}

void*  ll_foldr(t_ll *node, void*(f)(void* acc, t_ll* node), void *start)
{
  if (node == NULL)
    return (start);
  return (f(ll_foldr(node->next, f, start), node));
}

void ll_foreach(t_ll *node, void (f)(void* data, t_ll* node, int i))
{
  int i;

  for (i = 0; node != NULL; node = node->next, i++)
    f(node->data, node, i);
}
