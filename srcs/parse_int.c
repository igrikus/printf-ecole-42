#include "../includes/ft_printf.h"

char *str_from_arg(int parameters[5], va_list args)
{

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
	if (arg_contain_dot(arg))
		parameters[2] = YES;

	result = str_from_arg(parameters, args);
	list_args = ft_lstnew(result);
	return (ft_strlen(result));
}
