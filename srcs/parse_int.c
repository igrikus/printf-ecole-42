#include "../includes/ft_printf.h"

static char	*get_malloc_int_str(int number, size_t max_len,
								t_parameter parameter)
{
	char *result;

	if (number < 0 && parameter.num_before_dot <= parameter.num_after_dot)
		result = malloc(sizeof(char) * (max_len + 2));
	else
		result = malloc(sizeof(char) * (max_len + 1));
	if (result == 0)
		return (0);
	if (number < 0 && parameter.num_before_dot <= parameter.num_after_dot)
		ft_memset(result, 0, max_len + 2);
	else
		ft_memset(result, 0, max_len + 1);
	return (result);
}

static void get_result_str(t_sides side, int number,
					 size_t num_len, t_arg result)
{
	char *itoa_str;

	ft_memset(result.str, ' ', side.left);
	result.str += side.left;
	if (number < 0)
		*(result.str++) = '-';
	ft_memset(result.str, '0', side.null_left);
	result.str += side.null_left;
	itoa_str = ft_itoa(number);
	if (number < 0)
		itoa_str++;
	ft_strlcat(result.str, itoa_str, num_len + 1);
	if (number < 0)
		itoa_str--;
	free(itoa_str);
	result.str += num_len;
	ft_memset(result.str, ' ', side.right);
	result.str += side.right;
	*result.str = 0;
}

static t_arg str_from_arg(t_parameter parameter, int number)
{
	t_sides sides;
	t_arg result;
	size_t max_len;
	size_t num_len;

	num_len = get_num_len(number);
	if ((int)num_len >= parameter.num_before_dot
		&& (int)num_len >= parameter.num_after_dot)
	{
		result.str = ft_itoa(number);
		result.str_len = num_len;
		return (result);
	}
	if (parameter.num_before_dot > parameter.num_after_dot)
		max_len = parameter.num_before_dot;
	else
		max_len = parameter.num_after_dot;
	result.str = get_malloc_int_str(number, max_len, parameter);
	if (result.str == 0)
		return (result);
	sides = get_sides_int(parameter, max_len, num_len);
	if (number < 0 && sides.left)
		sides.left--;
	else if (number < 0 && sides.right)
		sides.right--;
	else if (number < 0 && sides.null_left && !parameter.contain_dot
	&& !sides.left && !sides.right)
		sides.null_left--;
	get_result_str(sides, number, num_len, result);
	return (result);
}

t_arg fill_result_if_number_zero(t_parameter parameter, t_arg result)
{
	if (parameter.num_before_dot == 0)
	{
		result.str = malloc(sizeof(char));
		result.str_len = 0;
		return (result);
	}
	result.str = malloc(sizeof(char) * (parameter.num_before_dot + 1));
	if (result.str == 0)
		return (result);
	ft_memset(result.str, ' ', parameter.num_before_dot);
	*(result.str + parameter.num_before_dot) = 0;
	result.str_len = ft_strlen(result.str);
	return (result);
}

size_t parse_int(const char *str, va_list args)
{
	t_parameter parameter;
	t_arg result;
	char *arg_str;
	int number;

	result.str = 0;
	result.str_len = 0;
	arg_str = ft_substr(str, 0, get_arg_len(str));
	if (arg_str == 0)
		return (0);
	parameter = fill_parameter(arg_str, args);
	number = va_arg(args, int);
	if (parameter.contain_dot && parameter.num_after_dot == 0 && number == 0)
		result = fill_result_if_number_zero(parameter, result);
	else
		result = str_from_arg(parameter, number);
	if (result.str == 0)
		return (0);
	fill_list(&result);
	free(arg_str);
	return (result.str_len);
}
