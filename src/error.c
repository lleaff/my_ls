#include <unistd.h>
#include <stdlib.h>
#include "my_ls.h"
#include "error.h"

void my_putcharerr(char c)
{
    write(STDERR_FILENO, &c, 1);
}

void my_puterr(char *msg)
{
    write(STDERR_FILENO, msg, my_strlen(msg));
}

int fail(char *msg)
{
    my_puterr(g_opts->colorize ? FG_RED : "");
    my_puterr(msg);
    my_puterr(g_opts->colorize ? COLOR_RESET : "");
    return (0);
}

void *fail_ptr(char *msg)
{
    my_puterr(g_opts->colorize ? FG_RED : "");
    my_puterr(msg);
    my_puterr(g_opts->colorize ? COLOR_RESET : "");
    return (NULL);
}
