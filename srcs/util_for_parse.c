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

int get_fill_num(const char *arg_str)
{
	int fill_num;

	fill_num = 0;
	while (*arg_str)
	{
		if (ft_isdigit(*arg_str))
			fill_num = ft_atoi(arg_str);
		arg_str++;
	}
	return (fill_num);
}
