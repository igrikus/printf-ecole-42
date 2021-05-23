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

t_parameter fill_parameter_with_null(t_parameter parameter)
{
	parameter.contain_dot = 0;
	parameter.contain_minus = 0;
	parameter.contain_zero = 0;
	parameter.num_after_dot = 0;
	parameter.num_before_dot = 0;
	return (parameter);
}