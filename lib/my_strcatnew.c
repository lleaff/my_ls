#include "lib.h"

char *my_strcatnew(char* pre, char* post)
{
  char *res;
  int  l_pre;
  int  l_post;
  
  l_pre = my_strlen(pre);
  l_post = my_strlen(post);
  if ((res = malloc(l_pre + l_post + 1)) == NULL)
    return (NULL);
  my_memcpy(res, pre, l_pre);
  my_memcpy(res + l_pre, post, l_post);
  res[l_pre + l_post] = '\0';
  return (res);
}
