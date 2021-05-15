#include "../includes/ft_printf.h"

//char *str_from_arg(int parameters[4], va_list args)
//{
//
//}
//
//size_t parse_int(const char *str, va_list args)
//{
//	int counter;
//	int parameters[4];
//	char *result;
//	const char *arg;
//
//	arg = ft_substr(str, 0, get_arg_len(str));
//	if (arg == 0)
//		return (0);
//	counter = 0;
//	while (counter < 4)
//		parameters[counter++] = NO;
//	if (arg_contain_zero(arg))
//		parameters[0] = YES;
//	if (arg_contain_minus(arg))
//		parameters[1] = YES;
//	parameters[2] = get_num_before_dot(arg);
//	if (parameters[2] == ASTERISK)
//		parameters[2] = va_arg(args, int);
//	if (arg_contain_dot(arg))
//		parameters[3] = get_num_after_dot(arg);
//	if (parameters[3] == ASTERISK)
//		parameters[3] = va_arg(args, int);
//	result = str_from_arg(parameters, args);
//	list_args = ft_lstnew(result);
//	return (ft_strlen(result));
//}
