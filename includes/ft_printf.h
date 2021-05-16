
#ifndef FT_PRINTF
# define FT_PRINTF

# define NO 0
# define YES 1
# define ASTERISK -1

#include "../libft/libft.h"
#include <stdarg.h>

size_t parse_int(const char *str, va_list list_args);
int get_arg_len(const char *str);
int arg_contain_minus(const char *arg_str);
int arg_contain_dot(const char *arg_str);
int arg_contain_zero(const char *arg_str);
int arg_contain_asterisk(const char *arg_str);
int get_fill_num(const char *arg_str);
int get_num_before_dot(const char *arg_str);
int get_num_after_dot(const char *arg_str);
int get_max_of_three(int first, int second, int third);
void fill_list(void *content);


t_list *list_args;

#endif
