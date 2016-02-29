#ifndef LIB_H
#define LIB_H

#include "macros.h"
#include "linkedlist.h"
#include "bool.h"
#include "colors.h"

void my_putchar(char c);
int  my_putstr(char* str);
int  my_putstrn(char* str, int n);
int  my_strlen(char *str);
void my_put_nbr(int n);
char *my_readfile(char* filename);
char *my_readline();
char *my_readnchars(int n);
char *my_itoa(int n);
int  my_getnbr(char *str);
int  is_int(char *str);
int  str_eq(char* str1, char* str2);
int  my_strncmp(char *s1, char *s2, int n);
char *my_strstr(char *str, char *to_find);
char **my_str_to_wordtab(char *str);
void my_strpush(char* dest, char* to_push);
void my_strnpush(char* dest, char* toPush, int n);

#ifdef DEBUG
#include "debug.h"
#endif

#endif /* LIB_H */
