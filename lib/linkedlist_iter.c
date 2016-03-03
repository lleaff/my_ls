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

typedef void*(t_ll_foldr_fn)(void* acc, t_ll* node);
static void*  _ll_foldr(t_ll *node, t_ll_foldr_fn f, void *start)
{
  void *res;
  void *next_val;

  if (node == NULL)
    return (start);
  next_val = ll_foldr(node->next, f, start);
  res = f(next_val, node);
  free(next_val);
  return (res);
}

void*  ll_foldr(t_ll *node, t_ll_foldr_fn f, void *start)
{
    return (_ll_foldr(node, f, start));
}

void ll_foreach(t_ll *node, void (f)(void* data, t_ll* node, int i))
{
  int i;

  for (i = 0; node != NULL; node = node->next, i++)
    f(node->data, node, i);
}
