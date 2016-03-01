#include "my_ls.h"

char *concat_paths(char *pre, char *post)
{
  int l_pre;
  int l_post;
  t_bool trailing_slash;
  char *res;

  l_pre  = my_strlen(pre);
  l_post = my_strlen(post);
  trailing_slash = pre[l_pre - 1] == '/';
  if ((res = malloc(l_pre + !trailing_slash + l_post + 1)) == NULL)
    return (NULL);
  my_memcpy(res, pre, l_pre);
  if (trailing_slash)
    res[l_pre] = '/';
  my_memcpy(res + l_pre + !trailing_slash, post, l_post);
  res[l_pre + !trailing_slash + l_post] = '\0';
  return (res);
}
