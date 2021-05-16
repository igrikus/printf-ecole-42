#include "../includes/ft_printf.h"

int get_arg_len(const char *str)
{
	int len;

	len = 0;
	while (*str && (*str > 13 || *str < 9))
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

int get_max_of_three(int first, int second, int third)
{
	int max;

	if (first >= second && first >= third)
		max = first;
	else if (second >= first && second >= third)
		max = second;
	else
		max = third;
	return (max);
}
