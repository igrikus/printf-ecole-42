#include "../includes/ft_printf.h"

static int	get_result_str(t_sides side, unsigned int number,
						   size_t num_len, char *result)
{
	char	*itoa_str;

	ft_memset(result, ' ', side.left);
	result += side.left;
	ft_memset(result, '0', side.null_left);
	result += side.null_left;
	itoa_str = ft_unsigned_itoa(number);
	if (itoa_str == 0)
		return (-1);
	ft_strlcat(result, itoa_str, num_len + 1);
	free(itoa_str);
	result += num_len;
	ft_memset(result, ' ', side.right);
	result += side.right;
	*result = 0;
	return (0);
}

static char	*str_from_arg(t_parameter parameter, unsigned int number,
						  size_t num_len)
{
	char	*itoa_str;
	char	*result;
	size_t	max_len;

	if ((int)num_len >= parameter.num_before_dot
		&& (int)num_len >= parameter.num_after_dot)
	{
		itoa_str = ft_unsigned_itoa(number);
		if (itoa_str)
			return (itoa_str);
		else
			return (0);
	}
	if (parameter.num_before_dot > parameter.num_after_dot)
		max_len = parameter.num_before_dot;
	else
		max_len = parameter.num_after_dot;
	result = get_malloc_result(max_len);
	if (result == 0)
		return (0);
	if (get_result_str(get_sides_int(parameter, max_len, num_len),
			number, num_len, result) == 0)
		return (result);
	else
		return (0);
}

size_t	parse_unsigned(const char *str, va_list args)
{
	t_parameter		parameter;
	char			*result;
	char			*arg_str;
	unsigned int	number;
	size_t			num_len;

	arg_str = ft_substr(str, 0, get_arg_len(str));
	if (arg_str == 0)
		return (0);
	parameter = fill_parameter(arg_str, args);
	number = va_arg(args, unsigned int);
	num_len = get_unsigned_num_len(number);
	if (parameter.contain_dot && parameter.num_after_dot == 0 && number == 0)
		result = fill_result_if_number_zero(parameter);
	else
		result = str_from_arg(parameter, number, num_len);
	if (result == 0)
		return (0);
	fill_list(result, ft_strlen(result));
	free(arg_str);
	return (ft_strlen(result));
}
