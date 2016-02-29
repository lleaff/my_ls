#include <unistd.h>

void my_putchar(char c)
{
    write(STDOUT_FILENO, &c, 1);
}
