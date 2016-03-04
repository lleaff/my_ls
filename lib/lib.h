#ifndef LIB_H
#define LIB_H

#include "macros.h"
#include "linkedlist.h"
#include "bool.h"
#include "colors.h"
#include "my_memcpy.h"

void   *noop(void *);
void   *noop2(void *, void *);
void   *my_memset(void *ptr, char byte, size_t n);
int    int_in_arr(int n, int *arr, int length);
void   my_putchar(char c);
int    my_putstr(char* str);
extern char g_fill_char;
int    my_putstrn(char* str, int n);
int    my_putstrnr(char* str, int n);
int    my_strlen(char *str);
void   my_put_nbr(int n);
void   my_put_longlong(long long n);
char   *my_readfile(char* filename);
char   *my_readline();
char   *my_readnchars(int n);
int    int_length_base(long n, int base);
int    int_length(long n);
char   *my_itoa(int n);
char   *my_longlongtoa(long long n);
int    my_getnbr(char *str);
int    is_int(char *str);
int    str_eq(char* str1, char* str2);
int    my_strcmp(char *s1, char *s2);
int    my_strncmp(char *s1, char *s2, int n);
int    char_in_str(char c, char *str);
char   *my_strstr(char *str, char *to_find);
char   **my_str_to_wordtab(char *str);
void   my_strpush(char* dest, char* to_push);
void   my_strnpush(char* dest, char* to_push, int n);
char   *last_n_chars(char* str, int n);
char   *my_strcatnew(char* pre, char* post);
char   *my_strnew(char *buffer);
char   *my_strnnew(char *buffer, int length);
char   *size_to_human_readable(long size);
/* Paths */
t_bool path_is_current(char *path);
char   *concat_paths(char *pre, char *post);
t_bool path_is_dot_ref(char *path);

#ifdef DEBUG
#include "debug.h"
#endif

#endif /* LIB_H */
