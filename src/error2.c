#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_ls.h"
#include "error.h"

t_bool print_fserr(char *begin, char *filename, char *end)
{
  fail(BIN_NAME": ");
  fail(begin);
  fail(filename);
  fail(": ");
  fail(end);
  my_putcharerr('\n');
  return (false);
};

t_bool file_error(char *f)
{
  my_puterr(FG_RED);
  my_puterr(BIN_NAME": ");
  perror(f);
  my_puterr(COLOR_RESET);
  return (false);
}

void *file_error_ptr(char *f)
{
  file_error(f);
  return (NULL);
}

/*
t_bool file_error(char *f)
{
  switch (errno) {
    case ENOENT:
      return (print_fserr("cannot access ", f, "No such file or directory"));
    default:
      return (print_fserr("Error with file ", f, ""));
  }
  return (false);
}
*/
