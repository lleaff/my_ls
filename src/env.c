#include <sys/ioctl.h>
#include <unistd.h>
#include "my_ls.h"

int get_window_columns()
{
    struct winsize s;

    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &s) != -1 && s.ws_col > 0)
        return (s.ws_col);
    return (-1);
}
