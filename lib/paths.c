#include "lib.h"

t_bool path_is_current(char *path)
{
  if (!my_strcmp(path, "."))
    return (true);
  else if (!my_strncmp(path, "./", 2))
    return (path_is_current(path + 2));
  else
    return (false);
}

char *concat_paths(char *pre, char *post)
{
  int l_pre;
  int l_post;
  t_bool trailing_slash;
  char *res;

  if (path_is_current(pre))
    return (my_strnew(post));
  if (path_is_current(post))
    return (my_strnew(pre));
  l_pre  = my_strlen(pre);
  l_post = my_strlen(post);
  trailing_slash = pre[l_pre - 1] == '/';
  if ((res = malloc(l_pre + !trailing_slash + l_post + 1)) == NULL)
    return (NULL);
  my_memcpy(res, pre, l_pre);
  if (!trailing_slash)
    res[l_pre] = '/';
  my_memcpy(res + l_pre + !trailing_slash, post, l_post);
  res[l_pre + !trailing_slash + l_post] = '\0';
  return (res);
}