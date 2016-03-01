#include "my_ls.h"

#define USAGE "USAGE: "BIN_NAME" [OPTION]... [FILE]...\n\n\
OPTIONS:\n\
  -l\t Long list format\n\
  -R\t Recursive\n\
  -r\t Reverse sort order\n\
  -d\t Don't follow links given as arguments\n\
  -t\t Sort by modification time\n\
  -a\t Include hidden files\n\
  -A\t Include hidden files except '.' and '..'\n\
  -L\t Dereference symbolic links\n\
  --help Print help\n\
"

t_bool print_usage(t_bool err)
{
  if (err)
    my_puterr(USAGE);
  else
    my_putstr(USAGE);
  
  return (false);
}
