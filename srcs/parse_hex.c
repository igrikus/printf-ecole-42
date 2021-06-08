#include "../includes/ft_printf.h"

static char	*get_hex_from_decimal(unsigned int nbr, char *base, char *result)
{
	unsigned int	modulo;

	if (nbr != 0 && (nbr / 16 != 0))
		result = get_hex_from_decimal(nbr / 16, base, result);
	modulo = nbr % 16;
	*result = base[modulo];
	return (result + 1);
}

static char	*fill_hex_str(char *arg_str, unsigned int number, size_t hex_len)
{
	char	*hex_str;

	hex_str = get_malloc_result(hex_len);
	if (hex_str == 0)
		return (0);
	if (flag_is_upper_hex(arg_str))
		get_hex_from_decimal(number, "0123456789ABCDEF", hex_str);
	else
		get_hex_from_decimal(number, "0123456789abcdef", hex_str);
	return (hex_str);
}

static int	get_result_str(t_sides side, char *arg_str,
						   unsigned int number, char *result)
{
	char	*hex_str;
	size_t	hex_len;

	hex_len = get_hex_len(number);
	hex_str = fill_hex_str(arg_str, number, hex_len);
	if (hex_str == 0)
		return (-1);
	ft_memset(result, ' ', side.left);
	result += side.left;
	ft_memset(result, '0', side.null_left);
	result += side.null_left;
	ft_strlcat(result, hex_str, hex_len + 1);
	free(hex_str);
	result += hex_len;
	ft_memset(result, ' ', side.right);
	result += side.right;
	*result = 0;
	return (0);
}

static char	*str_from_arg(t_parameter parameter, unsigned int number,
						  size_t num_len, char *arg_str)
{
	t_sides	sides;
	char	*result;
	size_t	max_len;

	if ((int)num_len >= parameter.num_before_dot
		&& (int)num_len >= parameter.num_after_dot)
		return (fill_hex_str(arg_str, number, num_len));
	if (parameter.num_before_dot > parameter.num_after_dot)
		max_len = parameter.num_before_dot;
	else
		max_len = parameter.num_after_dot;
	result = get_malloc_result(max_len);
	if (result == 0)
		return (0);
	sides = get_sides_int(parameter, max_len, num_len);
	if (get_result_str(sides, arg_str, number, result) == 0)
		return (result);
	else
		return (0);
}

size_t	parse_hex(const char *str, va_list args)
{
	t_parameter		parameter;
	char			*result;
	char			*arg_str;
	unsigned int	number;
	size_t			num_len;

	arg_str = ft_substr(str, 0, get_arg_len(str));
	if (arg_str == 0)
		return (0);
	parameter = fill_parameter(arg_str, args);
	number = va_arg(args, unsigned int);
	num_len = get_hex_len(number);
	if (parameter.contain_dot && parameter.num_after_dot == 0 && number == 0)
		result = fill_result_if_number_zero(parameter);
	else
		result = str_from_arg(parameter, number, num_len, arg_str);
	if (result == 0)
		return (0);
	fill_list(result, ft_strlen(result));
	free(arg_str);
	return (ft_strlen(result));
}
