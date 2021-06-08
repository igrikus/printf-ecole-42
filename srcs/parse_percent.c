#include "../includes/ft_printf.h"

void end_args_and_free_list(va_list args)
{
	va_end(args);
	ft_lstclear(&g_list_args, free_content);
}

static void get_result_str(t_sides sides, char *result)
{
	size_t count;

	count = 0;
	while (count++ < sides.left)
		*(result++) = ' ';
	count = 0;
	while (count++ < sides.null_left)
		*(result++) = '0';
	*(result++) = '%';
	count = 0;
	while (count++ < sides.right)
		*(result++) = ' ';
	*result = 0;
}

static char *str_from_arg(t_parameter parameter)
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
		*result = '%';
		*(result + 1) = 0;
		return (result);
	}
	sides = get_sides_percent(parameter, 1);
	get_result_str(sides, result);
	return (result);
}

size_t parse_percent(const char *str, va_list args)
{
	t_list *last;
	t_parameter parameter;
	char	*result;
	char	*arg_str;

	arg_str = ft_substr(str, 0, get_arg_len(str));
	if (arg_str == 0)
		return (0);
	if (!arg_contain_asterisk(arg_str))
		args = 0;
	parameter = fill_parameter(arg_str, args);
	result = str_from_arg(parameter);
	if (result == 0)
		return (0);
	free(arg_str);
	last = ft_lstlast(g_list_args);
	return (last->content_len);
}
