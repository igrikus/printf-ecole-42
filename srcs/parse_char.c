#include "../includes/ft_printf.h"

static void get_result_str(t_sides sides, char arg, char *result)
{
	size_t count;

	count = 0;
	while (count++ < sides.left)
		*(result++) = ' ';
	*(result++) = arg;
	count = 0;
	while (count++ < sides.right)
		*(result++) = ' ';
	*result = 0;
}

static char *str_from_arg(t_parameter parameter, char arg)
{
	t_sides sides;
	char *result;
	size_t max_len;

	if (parameter.num_before_dot)
		max_len = parameter.num_before_dot;
	else
		max_len = 1;
	result = get_malloc_result(max_len);
	if (result == 0)
		return (0);
	fill_list(result, max_len);
	if (max_len == 1)
	{
		*result = arg;
		*(result + 1) = 0;
		return (result);
	}
	sides = get_sides_str(parameter, 1);
	get_result_str(sides, arg, result);
	return (result);
}

size_t parse_char(const char *str, va_list args)
{
	t_list *last;
	t_parameter parameter;
	char	*result;
	char	*arg_str;
	char	arg;

	arg_str = ft_substr(str, 0, get_arg_len(str));
	if (arg_str == 0)
		return (0);
	parameter = fill_parameter(arg_str, args);
	arg = va_arg(args, int);
	result = str_from_arg(parameter, arg);
	if (result == 0)
		return (0);
	free(arg_str);
	last = ft_lstlast(list_args);
	return (last->content_len);
}
