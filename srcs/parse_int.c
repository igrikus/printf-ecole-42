#include "../includes/ft_printf.h"

int parse_int(const char *str, int *number)
{
	int side;
	int fill_num;
	char *result;
	const char *substr;

	substr = ft_substr(str, 0, get_arg_len(str));
	if (substr == 0)
		return (0);
	side = LEFT;
	if (arg_contain_minus(substr))
		side = RIGHT;
	fill_num = get_fill_num(substr);
}