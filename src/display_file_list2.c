#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "my_ls.h"

void print_files_stream(t_ll *files)
{
    int term_width;
    int line_width;
    t_bool last;

    term_width = get_window_columns();
    if (g_opts->oneentperline)
    {
        print_filenames_nocols(files);
        return ;
    }
    line_width = 0;
    ll_iter(files)
    {
        last = files->next == NULL;
        line_width += my_strlen(FINFO_LL_FILENAME(files)) + (!last * 4)
            + g_opts->filetypesymb;
        if (line_width > term_width)
        {
            my_putstr("\n");
            line_width = 0;
        }
        print_filename(files->data);
        my_putstr(last ? "\n" : ", ");
    }
}
