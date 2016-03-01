#include "my_ls.h"
#include "groups_and_users.h"

t_bool fill_longlist_info(t_ll *files, int *colsizes)
{
  return (fill_user_and_group(files, colsizes) &&
          fill_size(files, colsizes));
}

void print_file(t_finfo *finfo)
{
  print_filename(finfo);
  my_putchar(' ');
}

void print_file_long(t_finfo *finfo, int *colsizes)
{
  print_permissions(finfo);
  print_links_count(finfo);
  print_user(finfo, colsizes);
  print_group(finfo, colsizes);
  print_filesize(finfo, colsizes);
  print_mod_date(finfo);
  print_filename(finfo);
  print_link_info(finfo);
  my_putchar('\n');
}
