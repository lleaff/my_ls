#ifndef LONGLIST_INFO_H
#define LONGLIST_INFO_H

#include "my_ls.h"

t_bool fill_user_and_group(t_ll *files, int *colsizes);
t_bool fill_hardlink_count(t_ll *files, int *colsizes);

#endif /* LONGLIST_INFO_H */
