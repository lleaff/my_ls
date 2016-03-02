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
