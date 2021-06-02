#include "../includes/ft_printf.h"

static void get_result_str(t_sides side, unsigned int number,
						   size_t num_len, char *result)
{
	char *itoa_str;

	ft_memset(result, ' ', side.left);
	result += side.left;
	ft_memset(result, '0', side.null_left);
	result += side.null_left;
	itoa_str = ft_unsigned_itoa(number);
	ft_strlcat(result, itoa_str, num_len + 1);
	free(itoa_str);
	result += num_len;
	ft_memset(result, ' ', side.right);
	result += side.right;
	*result = 0;
}

static char *str_from_arg(t_parameter parameter, unsigned int number)
{
	t_sides sides;
	char *result;
	size_t max_len;
	size_t num_len;

	num_len = get_unsigned_num_len(number);
	if ((int)num_len >= parameter.num_before_dot
		&& (int)num_len >= parameter.num_after_dot)
		return (ft_unsigned_itoa(number));
	if (parameter.num_before_dot > parameter.num_after_dot)
		max_len = parameter.num_before_dot;
	else
		max_len = parameter.num_after_dot;
	result = get_malloc_result(max_len);
	if (result == 0)
		return (0);
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

size_t parse_unsigned(const char *str, va_list args)
{
	t_parameter parameter;
	char *result;
	char *arg_str;
	unsigned int number;

	arg_str = ft_substr(str, 0, get_arg_len(str));
	if (arg_str == 0)
		return (0);
	parameter = fill_parameter(arg_str, args);
	number = va_arg(args, unsigned int);
	if (parameter.contain_dot && parameter.num_after_dot == 0 && number == 0)
		result = fill_result_if_number_zero(parameter);
	else
		result = str_from_arg(parameter, number);
	if (result == 0)
		return (0);
	fill_list(result);
	free(arg_str);
	return (ft_strlen(result));
}
