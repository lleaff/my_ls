#ifndef ERROR_H
#define ERROR_H

void   my_putcharerr(char c);
void   my_puterr(char *msg);
int    fail(char *msg);
void   *fail_ptr(char *msg);
t_bool file_error(char *filename);
void   *file_error_ptr(char *f);
void   my_perror(char *str);


#endif /* ERROR_H */
