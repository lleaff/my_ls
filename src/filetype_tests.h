#ifndef FILETYPE_TESTS_H
#define FILETYPE_TESTS_H

t_bool finfo_is_dir(t_finfo *finfo);
t_bool finfo_is_executable(t_finfo *finfo);
t_bool finfo_is_link(t_finfo *finfo);
t_bool finfo_is_socket(t_finfo *finfo);
t_bool finfo_is_whiteout(t_finfo *finfo);
t_bool finfo_is_fifo(t_finfo *finfo);

#endif /* FILETYPE_TESTS_H */
