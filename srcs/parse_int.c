#include "../includes/ft_printf.h"

char	*get_malloc_result(int number, int max_len, t_parameter parameter)
{
	char *result;

	if (number < 0 && parameter.num_before_dot <= parameter.num_after_dot)
		result = malloc(sizeof(char) * (max_len + 2));
	else
		result = malloc(sizeof(char) * (max_len + 1));
	return (result);
}

void get_result_str(t_sides side, int number,
					 int num_len, char *result)
{
	char *itoa_str;

	ft_memset(result, ' ', side.left);
	result += side.left;
	if (number < 0)
		*(result++) = '-';
	ft_memset(result, '0', side.null_left);
	result += side.null_left;
	itoa_str = ft_itoa(number);
	if (number < 0)
		itoa_str++;
	ft_strlcat(result, itoa_str, num_len + 1);
	if (number < 0)
		itoa_str--;
	free(itoa_str);
	result += num_len;
	ft_memset(result, ' ', side.right);
	result += side.right;
	*result = 0;
}

char *str_from_arg(t_parameter parameter, int number)
{
	t_sides sides;
	char *result;
	int max_len;
	int num_len;

	num_len = get_num_len(number);
	if (num_len >= parameter.num_before_dot
		&& num_len >= parameter.num_after_dot)
		return (ft_itoa(number));
	if (parameter.num_before_dot > parameter.num_after_dot)
		max_len = parameter.num_before_dot;
	else
		max_len = parameter.num_after_dot;
	result = get_malloc_result(number, max_len, parameter);
	ft_memset(result, 0, max_len + 1);
	sides = get_sides(parameter, max_len, num_len);
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

char *fill_result_if_number_zero(t_parameter parameter)
{
	char *result;

	if (parameter.num_before_dot == 0)
	{
		result = malloc(sizeof(char));
		*result = 0;
		return (result);
	}
	result = malloc(sizeof(char) * (parameter.num_before_dot + 1));
	ft_memset(result, ' ', parameter.num_before_dot);
	*(result + parameter.num_before_dot) = 0;
	return (result);
}

size_t parse_int(const char *str, va_list args)
{
	t_parameter parameter;
	char *result;
	char *arg_str;
	int number;

	arg_str = ft_substr(str, 0, get_arg_len(str));
	if (arg_str == 0)
		return (0);
	parameter = fill_parameter(arg_str, args);
	number = va_arg(args, int);
	if (parameter.contain_dot && parameter.num_after_dot == 0 && number == 0)
		result = fill_result_if_number_zero(parameter);
	else
		result = str_from_arg(parameter, number);
	fill_list(result);
	free(arg_str);
	return (ft_strlen(result));
}
