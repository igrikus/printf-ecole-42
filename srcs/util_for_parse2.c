#include "../includes/printf.h"

int get_arg_len(const char *str)
{
	int len;

	len = 0;
	while (*str && (*str > 13 || *str < 9) && *str != ' ')
	{
		str++;
		len++;
	}
	return (len);
}

int get_num_before_dot(const char *arg_str)
{
	while (*arg_str && *arg_str != '.')
	{
		if (ft_isdigit(*arg_str))
			return (ft_atoi(arg_str));
		if (*arg_str == '*')
			return (ASTERISK);
		arg_str++;
	}
	return (0);
}

int get_num_after_dot(const char *arg_str)
{
	while (arg_str && *arg_str != '.')
		arg_str++;
	while (*arg_str)
	{
		if (ft_isdigit(*arg_str))
			return (ft_atoi(arg_str));
		if (*arg_str == '*')
			return (ASTERISK);
		arg_str++;
	}
	return (0);
}
