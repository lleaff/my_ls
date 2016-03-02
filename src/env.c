#include <sys/ioctl.h>
#include <unistd.h>
#include "my_ls.h"

int get_window_columns()
{
    struct winsize ws;

    if (ioctl (STDOUT_FILENO, TIOCGWINSZ, &ws) != -1 &&
        ws.ws_col > 0 && ws.ws_col == (size_t) ws.ws_col)
        return (ws.ws_col);

    return (-1);
}
