#include "longlist_info.h"
#include "pwd.h"
#include "grp.h"

#define BUFFSIZE 500

/*int max_group_l(t_ll *files)
{
  int max;
  int len;

  max = 0;
  ll_iter(files) {
    len = my_strlen(((t_finfo*)files->data)->group);
    if (len > max)
      max = len;
  }
  return (max);
}  */

int fill_group(t_finfo *f)
{
  struct group *grp;
  int gid;
  char *gr_name;

  gid = f->stats.st_gid;
  grp = getgrgid(gid);
  gr_name = (grp != NULL) ? grp->gr_name : my_itoa(gid);
  f->group = gr_name;
  return (my_strlen(gr_name));
}

/*
int max_user_l(t_ll *files)
{
  int max;
  int len;

  max = 0;
  ll_iter(files) {
    len = my_strlen(((t_finfo*)files->data)->user);
    if (len > max)
      max = len;
  }
  return (max);
}  */

int fill_user(t_finfo *f)
{
  struct passwd *pwd;
  int uid;
  char *us_name;

  uid = f->stats.st_gid;
  pwd = getpwuid(uid);
  us_name = (pwd != NULL) ? pwd->pw_name : my_itoa(uid);
  f->user = us_name;
  return (my_strlen(us_name));
}

t_bool fill_user_and_group(t_ll *files, int *colsizes)
{
  t_finfo *finfo;
  int max_user_len;
  int max_group_len;
  int l;

  max_user_len = 0;
  max_group_len = 0;
  ll_iter(files) {
    finfo = (t_finfo*)files->data;
    l = fill_user(finfo);
    if (l > max_user_len)
      max_user_len = l;
    l = fill_group(finfo);
    if (l > max_group_len)
      max_group_len = l;
  }
  colsizes[COL_USER]  = MIN(MAX_COL_SIZE, max_user_len);
  colsizes[COL_GROUP] = MIN(MAX_COL_SIZE, max_group_len);
  return (true);
}

t_bool fill_hardlink_count(t_ll *files, int *colsizes)
{
  int max_links_len;
  int len;
  t_finfo *finfo;

  max_links_len = 0;
  ll_iter(files) {
    finfo = (t_finfo*)files->data;
    finfo->hardlinks = finfo->stats.st_nlink;
    finfo->hardlinksstr = my_itoa(finfo->hardlinks);
    len = my_strlen(finfo->hardlinksstr);
    max_links_len = MAX(max_links_len, len);
  }
  colsizes[COL_HARDLINKS] = max_links_len;
  return (true);
}
