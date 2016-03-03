#define _GNU_SOURCE /* needed for lstat and readlink with gcc */

#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "my_ls.h"

#define FINFO_MODE(f) ((f)->stats.st_mode)
#define FINFO_MODE_MASK(f) (FINFO_MODE(f) & S_IFMT)

t_bool finfo_is_executable(t_finfo *finfo)
{
    return (S_IXUSR & FINFO_MODE(finfo));
}

t_bool finfo_is_link(t_finfo *finfo)
{
    return (FINFO_MODE_MASK(finfo) == S_IFLNK);
}

t_bool finfo_is_socket(t_finfo *finfo)
{
    return (FINFO_MODE_MASK(finfo) == S_IFSOCK);
}

t_bool finfo_is_whiteout(t_finfo *finfo)
{
#ifdef S_IFWHT
    return (FINFO_MODE_MASK(finfo) == S_IFWHT);
#else
    return (false);
#endif
}

t_bool finfo_is_fifo(t_finfo *finfo)
{
    return (FINFO_MODE_MASK(finfo) == S_IFIFO);
}
