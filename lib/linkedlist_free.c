#include <stdlib.h>
#include "linkedlist.h"

void ll_free(t_ll* node)
{
    if (node != NULL)
    {
        ll_free(node->next);
        free(node->data);
        free(node);
    }
}

void ll_free_nodata(t_ll* node)
{
    if (node != NULL)
    {
        ll_free_nodata(node->next);
        free(node);
    }
}
