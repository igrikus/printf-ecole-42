#include "../includes/ft_printf.h"

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
	char *itoa_str;

	if (number < 0 && side.left)
		side.left--;
	else if (number < 0 && side.right)
		side.right--;
	ft_memset(result, ' ', side.left);
	result += side.left;
	if (number < 0)
	{
		*(result++) = '-';
		number *= -1;
	}
	ft_memset(result, '0', side.null_left);
	result += side.null_left;
	itoa_str = ft_itoa(number);
	ft_strlcat(result, itoa_str, num_len + 1);
	free(itoa_str);
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
	char *arg_str;
	int number;

	arg_str = ft_substr(str, 0, get_arg_len(str));
	if (arg_str == 0)
		return (0);
	parameter = fill_parameter(arg_str, args);
	number = va_arg(args, int);
	if (parameter.contain_dot && parameter.num_after_dot == 0 && number == 0)
	{
		result = malloc(sizeof(char));
		*result = 0;
	}
	else
		result = str_from_arg(parameter, number);
	fill_list(result);
	free(arg_str);
	return (ft_strlen(result));
}
