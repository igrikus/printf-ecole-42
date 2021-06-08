#include "../includes/ft_printf.h"

int	get_arg_len(const char *str)
{
	char	*flags;
	int		len;

	len = 1;
	str++;
	flags = "cspdiuxX";
	while (*str && (*str > 13 || *str < 9) && *str != ' '
		   && ft_memchr(flags, *(str - 1), 8) == 0)
	{
		len++;
		str++;
		if (*(str - 1) == '%')
			break ;
	}
	return (len);
}

int	flag_is_upper_hex(const char *arg_str)
{
	while (*arg_str)
	{
		if (*arg_str == 'X')
			return (YES);
		arg_str++;
	}
	return (NO);
}

int	get_unsigned_num_len(unsigned int num)
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

int	get_num_before_dot(const char *arg_str)
{
	while (*arg_str && *arg_str != '.')
	{
		if (ft_isdigit(*arg_str) && *arg_str != '0')
			return (ft_atoi(arg_str));
		if (*arg_str == '*')
			return (ASTERISK);
		arg_str++;
	}
	return (0);
}

int	get_num_after_dot(const char *arg_str)
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
