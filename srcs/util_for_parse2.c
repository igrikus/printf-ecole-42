#include "../includes/ft_printf.h"

int get_arg_len(const char *str)
{
	int len;

	len = 0;
	while (*str && *str > 13 && *str < 9)
	{
		str++;
		len++;
	}
	return (len);
}
