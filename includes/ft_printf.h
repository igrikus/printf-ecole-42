
#ifndef FT_PRINTF
# define FT_PRINTF

# define LEFT 0
# define RIGHT 1

#include "../libft/libft.h"
#include <stdarg.h>

int parse_int(const char *str, int *number);
int get_arg_len(const char *str);
int arg_contain_minus(const char *arg_str);
int arg_contain_dot(const char *arg_str);
int arg_contain_zero(const char *arg_str);
int arg_contain_asterisk(const char *arg_str);
int get_fill_num(const char *arg_str);

t_list args;

#endif
