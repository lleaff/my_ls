#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "my_ls.h"
#include "longlist_info.h"

#define IS_EXECUTABLE(finfo) ((finfo)->stats.st_mode & S_IXUSR)

void print_filename(t_finfo *finfo)
{
  char *color;
  char filetypesym;
  
  if (finfo->islink)
    color = FCOLOR_LINK;
  else if (finfo->isdir)
    color = FCOLOR_DIR;
  else if (IS_EXECUTABLE(finfo))
    color = FCOLOR_EXECUTABLE;
  else
    color = "";
  my_putstr(g_opts->colorize ? color : "");
  my_putstr(finfo->filename);
  my_putstr(g_opts->colorize ? COLOR_RESET : "");
  if (g_opts->filetypesymb)
  {
      filetypesym = get_filetype_symbol(finfo);
      if (!(g_opts->streamformat && filetypesym == ' '))
          my_putchar(filetypesym);
  }
}

void print_permissions(t_finfo *finfo)
{
  mode_t m;

  m = finfo->stats.st_mode;
  my_putchar(get_filetype_char(m));
  my_putchar(S_IRUSR & m ? 'r' : '-');
  my_putchar(S_IWUSR & m ? 'w' : '-');
  my_putchar(S_IXUSR & m ? 'x' : '-');
  my_putchar(S_IRGRP & m ? 'r' : '-');
  my_putchar(S_IWGRP & m ? 'w' : '-');
  my_putchar(S_IXGRP & m ? 'x' : '-');
  my_putchar(S_IROTH & m ? 'r' : '-');
  my_putchar(S_IWOTH & m ? 'w' : '-');
  my_putchar(S_IXOTH & m ? 'x' : '-');
  print_gutter();
}

void print_links_count(t_finfo *f, int *colsizes)
{
  my_putstrnr(f->hardlinksstr, colsizes[COL_HARDLINKS]);
  my_putchar(' ');
}

void print_user(t_finfo *finfo, int *colsizes)
{
  my_putstrn(finfo->user, colsizes[COL_USER]);
  print_gutter();
}

void print_group(t_finfo *finfo, int *colsizes)
{
  my_putstrn(finfo->group, colsizes[COL_GROUP]);
  print_gutter();
}
