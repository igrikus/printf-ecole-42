#include "../includes/printf.h"

int get_num_len(int num)
{
	int	len;

	len = 1;
	while (num != 0)
	{
		num /= 10;
		if (num != 0)
			len++;
	}
	return (len);
}

void get_result_str(t_sides side, int number,
					 int num_len, char *result)
{
	ft_memset(result, ' ', side.left);
	result += side.left;
	ft_memset(result, '0', side.null_left);
	result += side.null_left;
	ft_strlcat(result, ft_itoa(number), num_len + 1);
	result += num_len;
	ft_memset(result, '0', side.null_right);
	result += side.null_right;
	ft_memset(result, ' ', side.right);
	result += side.right;
	*result = 0;
}

char *str_from_arg(t_parameter parameter, int number)
{
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
	result = malloc(max_len + 1);
	ft_memset(result, 0, max_len + 1);
	get_result_str(get_sides(parameter, max_len, num_len),
				number, num_len, result);
	return (result);
}

size_t parse_int(const char *str, va_list args)
{
	t_parameter parameter;
	char *result;
	char *arg;

	arg = ft_substr(str, 0, get_arg_len(str));
	if (arg == 0)
		return (0);
	if (arg_contain_zero(arg))
		parameter.contain_zero = YES;
	if (arg_contain_minus(arg))
		parameter.contain_minus = YES;
	parameter.num_before_dot = get_num_before_dot(arg);
	if (parameter.num_before_dot == ASTERISK)
		parameter.num_before_dot = va_arg(args, int);
	if ((parameter.contain_dot = arg_contain_dot(arg)))
		parameter.num_after_dot = get_num_after_dot(arg);
	if (parameter.num_after_dot == ASTERISK)
		parameter.num_after_dot = va_arg(args, int);
	result = str_from_arg(parameter, va_arg(args, int));
	fill_list(result);
	free(arg);
	return (ft_strlen(result));
}
