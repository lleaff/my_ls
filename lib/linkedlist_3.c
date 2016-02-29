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
