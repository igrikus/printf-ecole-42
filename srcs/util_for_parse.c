#include "../includes/ft_printf.h"

int arg_contain_minus(const char *arg_str)
{
	while(*arg_str)
	{
		if (*arg_str == '-')
			return (1);
		arg_str++;
	}
	return (0);
}

int arg_contain_dot(const char *arg_str)
{
	while(*arg_str)
	{
		if (*arg_str == '.')
			return (1);
		arg_str++;
	}
	return (0);
}

int arg_contain_zero(const char *arg_str)
{
	while(*arg_str)
	{
		if (ft_isdigit(*arg_str))
		{
			if (*arg_str == '0')
				return (1);
			else
				return (0);
		}
		arg_str++;
	}
	return (0);
}

int arg_contain_asterisk(const char *arg_str)
{
	while(*arg_str)
	{
		if (*arg_str == '*')
			return (1);
		arg_str++;
	}
	return (0);
}
