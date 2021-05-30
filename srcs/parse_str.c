#include "../includes/ft_printf.h"

char *trim_arg_str(t_parameter parameter, char *arg, size_t arg_len)
{
	char *result;
	int count;

	count = 0;
	if (parameter.contain_dot && parameter.num_after_dot >= 0)
	{
		result = malloc(sizeof(char) * (parameter.num_before_dot + 1));
		while (*arg && count < parameter.num_after_dot)
		{
			*(result++) = *(arg++);
			count++;
		}
	}
	else
	{
		result = malloc(sizeof(char) * (arg_len + 1));
		while ((size_t) count < arg_len)
		{
			*(result++) = *(arg++);
			count++;
		}
	}
	*result = 0;
	return (result - count);
}

static void get_result_str(t_sides sides, char *trim_str,
						   size_t trim_str_len, char *result)
{
	size_t count;

	count = 0;
	while (count++ < sides.left)
		*(result++) = ' ';
	ft_strlcat(result, trim_str, trim_str_len + 1);
	result += trim_str_len;
	count = 0;
	while (count++ < sides.right)
		*(result++) = ' ';
	*result = 0;
}

static char *str_from_arg(t_parameter parameter, char *arg)
{
	t_sides sides;
	char *result;
	char *trim_str;
	size_t max_len;
	size_t str_len;

	str_len = ft_strlen(arg);
	trim_str = trim_arg_str(parameter, arg, str_len);
	if (str_len < ft_strlen(trim_str))
		max_len = str_len;
	else
		max_len = parameter.num_before_dot;
	str_len = ft_strlen(trim_str);
	result = malloc(sizeof(char) * (max_len + 1));
	if (result == 0)
		return (0);
	ft_memset(result, 0, max_len + 1);
	if (str_len >= (size_t) parameter.num_before_dot)
	{
		ft_strlcat(result, trim_str, str_len + 1);
		free(trim_str);
		return (result);
	}
	sides = get_sides_str(parameter, str_len);
	get_result_str(sides, trim_str, str_len, result);
	free(trim_str);
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
		arg = "(null)";
	result = str_from_arg(parameter, arg);
	if (result == 0)
		return (0);
	fill_list(result);
	free(arg_str);
	return (ft_strlen(result));
}
