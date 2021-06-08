#include "../includes/ft_printf.h"

t_sides	get_sides_percent(t_parameter parameter, size_t arg_len)
{
	t_sides	side;

	side.left = 0;
	side.null_left = 0;
	side.right = 0;
	if (parameter.contain_minus)
		side.right = parameter.num_before_dot - arg_len;
	else if (parameter.contain_zero)
		side.null_left = parameter.num_before_dot - arg_len;
	else
		side.left = parameter.num_before_dot - arg_len;
	return (side);
}
