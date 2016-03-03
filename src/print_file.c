#include "my_ls.h"
#include "longlist_info.h"

t_bool fill_longlist_info(t_ll *files, int *colsizes)
{
  return (fill_hardlink_count(files, colsizes) &&
          fill_user_and_group(files, colsizes) &&
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
  print_links_count(finfo, colsizes);
  if (!g_opts->longlistgroup)
      print_user(finfo, colsizes);
  print_group(finfo, colsizes);
  print_filesize(finfo, colsizes);
  print_mod_date(finfo);
  print_filename(finfo);
  print_link_info(finfo);
  my_putchar('\n');
}

#if defined(__unix__) || (defined(__APPLE__) && defined(__MACH__))
#define BS_DIV 1
#else
#define BS_DIV 2
#endif

void display_total_blocks(t_ll *files)
{
    int total;

    total = 0;
    ll_iter(files)
    {
        total += ((t_finfo*)files->data)->stats.st_blocks / BS_DIV;
    }
    my_putstr("total ");
    my_put_nbr(total);
    my_putchar('\n');
}
