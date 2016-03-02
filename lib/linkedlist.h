#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>
#include "my_memcpy.h"

typedef int t_comparison_fn(const void*, const void*);

typedef struct s_ll {
    struct s_ll* next;
    void* data;
} t_ll;

t_ll*  ll_new(void* data);
t_ll*  ll_new_n(void* data, int n);
t_ll*  ll_new_data(void* data, int size);
t_ll*  ll_new_data_n(void* data, int size, int n);

t_ll*  ll_last(t_ll* node);
t_ll*  ll_init(t_ll* node);

int    ll_length(t_ll* node);
int    ll_length_gt(t_ll *node, int n);
t_ll*  ll_nth(t_ll* node, int n);

int    ll_remove(t_ll** begin, t_ll* toRemove);
t_ll*  ll_append(t_ll* node, t_ll* toAppend);
t_ll*  ll_from_arr(int elSize, int count, void* array);
t_ll*  ll_from_lines(char* str);
t_ll*  ll_search(t_ll* node, void* value, int (*cmp)(void*, void*));
void   ll_swap(t_ll* node1, t_ll* node2);
t_ll*  ll_copy(t_ll* node);
t_ll*  ll_copy_data(t_ll* node, int size);

void   ll_free(t_ll* node);
void   ll_free_nodata(t_ll* node);

void   ll_sort(t_ll *node, t_comparison_fn);

t_ll*  ll_map(t_ll *node, void*(f)(t_ll* node));
void*  ll_foldr(t_ll *node, void*(f)(void* acc, t_ll* node), void *start);
void   ll_foreach(t_ll *node, void (f)(void* data, t_ll* node, int i));

void   ll_print_strings(t_ll* node, char *delim);
#ifdef DEBUG
void   ll_debug_strings(t_ll* node);
void   ll_debug_ints(t_ll* node);
#endif /* DEBUG */

#define ll_iter(node) \
    for (; node != NULL; node = node->next)

#endif /* LINKEDLIST_H */
