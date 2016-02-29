#include "linkedlist.h"

t_ll* ll_search(t_ll* node, void* value, int (*cmp)(void*, void*))
{
  for (; node != NULL; node = node->next)
    {
      if (!cmp(value, node->data))
        return (node);
    }
  return (NULL);
}

t_ll* ll_copy(t_ll* node)
{
  t_ll* copied;

  if (node == NULL)
    return (NULL);
  copied = ll_new(node->data);
  copied->next = ll_copy(node->next);
  return (copied);
}

t_ll* ll_new_data(void* data, int size)
{
    t_ll* node;
    void* ndata;

    if ((node = malloc(sizeof(t_ll))) == NULL)
      return NULL;
    if ((ndata = malloc(size)) == NULL)
      return (NULL);

    node->data = my_memcpy(ndata, data, size);
    node->next = NULL;
    return node;
}

t_ll* ll_copy_data(t_ll* node, int size)
{
  t_ll* copied;

  if (node == NULL)
    return (NULL);
  copied = ll_new_data(node->data, size);
  copied->next = ll_copy_data(node->next, size);
  return (copied);
}

t_ll* ll_from_lines(char *str)
{
    t_ll* res;
    int i;
    char* line;
    int len;

    res = NULL;
    for (i = 0; str[i]; str += i + 1, i = 0)
    {
        while (str[i] != '\n' && str[i])
            i++;
        if (!str[i])
            break ;
        len = sizeof(char) * i + 1;
        if ((line = malloc(len)) == NULL)
                return (NULL);
        line = my_memcpy(line, str, len);
        line[len - 1] = '\0';
        res = ll_append(res, ll_new_data(line, len));
    }
    return (res);
}
