#include "linkedlist.h"

t_ll*  ll_new_n(void* data, int n)
{
  t_ll *node;

  for (node = NULL; n > 0; n--)
    node = ll_append(node, ll_new(data));
  return (node);
}

t_ll*  ll_new_data_n(void* data, int size, int n)
{
  t_ll *node;

  for (node = NULL; n > 0; n--)
    node = ll_append(node, ll_new_data(data, size));
  return (node);
}

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
