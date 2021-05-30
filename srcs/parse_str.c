#include "../includes/ft_printf.h"

char *trim_arg_str(t_parameter parameter, char *arg, char *result)
{
	size_t arg_len;
	int count;

	count = 0;
	if (parameter.contain_dot)
	{
		while (*arg && count < parameter.num_after_dot)
		{
			*(result++) = *(arg++);
			count++;
		}
	} else
	{
		arg_len = ft_strlen(arg);
		while ((size_t)count < arg_len)
		{
			*(result++) = *(arg++);
			count++;
		}
	}
	result -= count;
	return (result);
}

static void get_result_str(t_sides sides, t_parameter parameter,
					char *arg, char *result)
{
	size_t arg_len;
	size_t count;

	arg_len = ft_strlen(arg);
	count = 0;
	while (count++ < sides.left)
		*(result++) = ' ';
	result = trim_arg_str(parameter, arg, result);
	result += arg_len;
	count = 0;
	while (count++ < sides.right)
		*(result++) = ' ';
	*result = 0;
}

static char *str_from_arg(t_parameter parameter, char *arg)
{
	t_sides sides;
	char *result;
	size_t max_len;
	size_t str_len;

	str_len = ft_strlen(arg);
	if (str_len >= (size_t) parameter.num_before_dot)
		max_len = str_len;
	else
		max_len = parameter.num_before_dot;
	result = malloc(sizeof(char) * (max_len + 1));
	if (result == 0)
		return (0);
	ft_memset(result, 0, max_len + 1);
	if (str_len >= (size_t) parameter.num_before_dot)
		return (trim_arg_str(parameter, arg, result));
	sides = get_sides_str(parameter, str_len);
	get_result_str(sides, parameter, arg, result);
	return (result);
}

size_t parse_str(const char *str, va_list args)
{
	t_parameter parameter;
	char	*result;
	char	*arg_str;
	char	*arg;

	arg_str = ft_substr(str, 0, get_arg_len(str));
	if (arg_str == 0)
		return (0);
	parameter = fill_parameter(arg_str, args);
	arg = va_arg(args, char *);
	if (arg == 0)
		arg = "";
	result = str_from_arg(parameter, arg);
	if (result == 0)
		return (0);
	fill_list(result);
	free(arg_str);
	return (ft_strlen(result));
}
