
#ifndef FT_PRINTF
# define FT_PRINTF

# define NO 0
# define YES 1
# define ASTERISK -1

#include "../libft/libft.h"
#include <stdarg.h>

typedef struct	s_parameter
{
	int contain_zero;
	int contain_minus;
	int num_before_dot;
	int contain_dot;
	int num_after_dot;
}				t_parameter;

typedef struct	s_sides
{
	size_t left;
	size_t null_left;
	size_t right;
}				t_sides;

int ft_printf(const char *str, ...);
size_t parse_int(const char *str, va_list list_args);
size_t parse_str(const char *str, va_list args);
int get_arg_len(const char *str);
int arg_contain_minus(const char *arg_str);
int arg_contain_dot(const char *arg_str);
int arg_contain_zero(const char *arg_str);
int get_num_before_dot(const char *arg_str);
int get_num_after_dot(const char *arg_str);
void fill_list(void *content);
void free_content(void *content);
t_sides get_sides_int(t_parameter parameter, int max_len, int arg_len);
t_sides get_sides_str(t_parameter parameter, size_t arg_len);
t_parameter fill_parameter(char *arg_str, va_list args);
int get_num_len(int num);

t_list *list_args;

#endif
