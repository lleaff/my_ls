#include <stdlib.h>
#include "linkedlist.h"
#include "lib.h"
#include "my_memcpy.h"

t_ll* ll_from_arr(int elSize, int count, void* array)
{
    t_ll* begin;
    t_ll* prev;
    t_ll* node;
    void* data;
    int n;

    prev = NULL;
    begin = NULL;
    for (n = 0; n < count; n++)
    {
        if ((data = malloc(elSize)) == NULL)
            return NULL;
        my_memcpy(data, (char*)array + (elSize * n), elSize);
        node = ll_new(data);
        if (prev)
            prev->next = node;
        prev = node;
        if (!begin)
            begin = node;
    }
    return begin;
}

t_ll* ll_nth(t_ll* node, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (node == NULL)
            return NULL;
        node = node->next;
    }
    return node;
}

int ll_length(t_ll* node)
{
    int n;

    for (n = 0; node; n++)
        node = node->next;
    return n;
}

void ll_swap(t_ll* node1, t_ll* node2)
{
  void *tmp;

  tmp = node1->data;
  node1->data = node2->data;
  node2->data = tmp;
}
