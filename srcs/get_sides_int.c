#include "../includes/ft_printf.h"

static t_sides	get_side_if_contain_dot(t_sides side, t_parameter parameter,
									   size_t max_len, size_t arg_len)
{
	if (parameter.num_before_dot > parameter.num_after_dot)
	{
		if (parameter.contain_minus)
		{
			if (parameter.num_after_dot > (int) arg_len)
				side.right = parameter.num_before_dot - parameter.num_after_dot;
			else
				side.right = parameter.num_before_dot - arg_len;
		}
		else
		{
			if (parameter.num_after_dot > (int) arg_len)
				side.left = parameter.num_before_dot - parameter.num_after_dot;
			else
				side.left = parameter.num_before_dot - arg_len;
		}
	}
	if (parameter.num_after_dot < 0 && !side.right && parameter.contain_zero)
	{
		side.left = 0;
		side.null_left = max_len - arg_len;
	}
	else
		side.null_left = max_len - arg_len - side.right - side.left;
	return (side);
}

static t_sides	get_side_if_no_dot(t_sides side, t_parameter parameter,
								  size_t arg_len)
{
	if (parameter.contain_minus)
	{
		side.right = parameter.num_before_dot - arg_len;
	}
	else
	{
		if (parameter.contain_zero)
			side.null_left = parameter.num_before_dot - arg_len;
		else
			side.left = parameter.num_before_dot - arg_len;
	}
	return (side);
}

t_sides	get_sides_int(t_parameter parameter, size_t max_len, size_t arg_len)
{
	t_sides	side;

	side.left = 0;
	side.null_left = 0;
	side.right = 0;
	if (parameter.contain_dot)
		side = get_side_if_contain_dot(side, parameter, max_len, arg_len);
	else
		side = get_side_if_no_dot(side, parameter, arg_len);
	return (side);
}
