#include <stdlib.h>
#include "linkedlist.h"
#include "lib.h"

t_ll* ll_new(void* data)
{
    t_ll* node;

    if ((node = malloc(sizeof(t_ll))) == NULL)
        return NULL;

    node->data = data;
    node->next = NULL;
    return node;
}

t_ll* ll_last(t_ll* node)
{
    while (node->next != NULL)
        node = node->next;
    return node;
}

t_ll* ll_append(t_ll* node, t_ll* toAppend)
{
    if (node) {
        ll_last(node)->next = toAppend;
    } else {
        node = toAppend;
    }
    return node;
}

int ll_remove(t_ll** begin, t_ll* toRemove)
{
    t_ll* prev;
    t_ll* node;

    prev = NULL;
    node = *begin;
    while (node != NULL)
    {
        if (node == toRemove)
        {
            free(node->data);
            if (prev)
                prev->next = node->next;
            else
                *begin = node;
            return 1;
        }
        prev = node;
        node = node->next;
    }
    return 0;
}

t_ll* ll_init(t_ll* node)
{
    ll_remove(&node, ll_last(node));
    return node;
}
