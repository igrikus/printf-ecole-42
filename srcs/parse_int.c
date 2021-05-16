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

char *str_from_arg(const int parameters[5], int number)
{
	char *result;
	int counter;
	int num_len;
	int malloc_size;

	num_len = get_num_len(number);
	if (num_len >= parameters[2] && num_len >= parameters[4])
		return (ft_itoa(number));
	if (parameters[2] > parameters[4])
		malloc_size = parameters[2];
	else
		malloc_size = parameters[4];
	result = malloc(malloc_size + 1);
	counter = 0;
	return (0);
}

size_t parse_int(const char *str, va_list args)
{
	int counter;
	int parameters[5];
	char *result;
	const char *arg;

	arg = ft_substr(str, 0, get_arg_len(str));
	if (arg == 0)
		return (0);
	counter = 0;
	while (counter < 4)
		parameters[counter++] = NO;
	if (arg_contain_zero(arg))
		parameters[0] = YES;
	if (arg_contain_minus(arg))
		parameters[1] = YES;
	parameters[2] = get_num_before_dot(arg);
	if (parameters[2] == ASTERISK)
		parameters[2] = va_arg(args, int);
	if ((parameters[3] = arg_contain_dot(arg)))
		parameters[4] = get_num_after_dot(arg);
	if (parameters[4] == ASTERISK)
		parameters[4] = va_arg(args, int);
	result = str_from_arg(parameters, va_arg(args, int));
	fill_list(result);
	return (ft_strlen(result));
}
