#include "../includes/ft_printf.h"

int arg_contain_minus(const char *arg_str)
{
	while(*arg_str)
	{
		if (*arg_str == '-')
			return (YES);
		arg_str++;
	}
	return (NO);
}

int arg_contain_dot(const char *arg_str)
{
	while(*arg_str)
	{
		if (*arg_str == '.')
			return (YES);
		arg_str++;
	}
	return (NO);
}

int arg_contain_zero(const char *arg_str)
{
	while(*arg_str)
	{
		if (ft_isdigit(*arg_str))
		{
			if (*arg_str == '0')
				return (YES);
			else
				return (NO);
		}
		arg_str++;
	}
	return (NO);
}

int arg_contain_asterisk(const char *arg_str)
{
	while(*arg_str)
	{
		if (*arg_str == '*')
			return (YES);
		arg_str++;
	}
	return (NO);
}

t_parameter fill_parameter(char *arg_str, va_list args)
{
	t_parameter parameter;

	parameter.contain_dot = 0;
	parameter.contain_minus = 0;
	parameter.contain_zero = 0;
	parameter.num_after_dot = 0;
	parameter.num_before_dot = 0;
	if (arg_contain_zero(arg_str))
		parameter.contain_zero = YES;
	if (arg_contain_minus(arg_str))
		parameter.contain_minus = YES;
	parameter.num_before_dot = get_num_before_dot(arg_str);
	if (parameter.num_before_dot == ASTERISK)
		parameter.num_before_dot = va_arg(args, int);
	if ((parameter.contain_dot = arg_contain_dot(arg_str)))
		parameter.num_after_dot = get_num_after_dot(arg_str);
	if (parameter.num_after_dot == ASTERISK)
		parameter.num_after_dot = va_arg(args, int);
	return (parameter);
}
