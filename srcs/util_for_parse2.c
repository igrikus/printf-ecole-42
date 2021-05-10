#include "../includes/ft_printf.h"

int get_arg_len(const char *str)
{
	int len;

	len = 0;
	while (*str && *str != ' ')
	{
		str++;
		len++;
	}
	return (len);
}

