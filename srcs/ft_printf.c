#include "../includes/ft_printf.h"

char	*concat_arg(char *result, char *temp_for_free)
{
	char *arg;
	size_t count;

	if (g_list_args == 0)
	{
		free(temp_for_free);
		return (0);
	}
	arg = g_list_args->content;
	count = 0;
	while (count < g_list_args->content_len)
	{
		*(result + count) = *(arg + count);
		count++;
	}
	result += g_list_args->content_len;
	g_list_args = g_list_args->next;
	return (result);
}

char *get_result_line(const char *str, size_t size)
{
	t_list *temp;
	int arg_len;
	char *result;
	char *temp_for_free;

	result = get_malloc_result(size);
	if (result == 0)
		return (0);
	temp_for_free = result;
	temp = g_list_args;
	while (*str)
		if (*str == '%')
		{
			arg_len = get_arg_len(str);
			result = concat_arg(result, temp_for_free);
			if (result == 0)
				return (0);
			str += arg_len;
		}
		else
			*(result++) = *(str++);
	g_list_args = temp;
	*result = 0;
	return (result - size);
}

size_t get_arg_size(const char *str, va_list args)
{
	int	i;
	char symbol;

	i = 1;
	symbol = *(str + i);
	while (symbol)
	{
		if (symbol == 'd' || symbol == 'i')
			return (parse_int(str, args));
		else if (symbol == 's')
			return (parse_str(str, args));
		else if (symbol == 'c')
			return (parse_char(str, args));
		else if (symbol == 'p')
			return (parse_pointer(str, args));
		else if (symbol == 'u')
			return (parse_unsigned(str, args));
		else if (symbol == 'x' || symbol == 'X')
			return (parse_hex(str, args));
		else if (symbol == '%')
			return (parse_percent(str, args));
		i++;
		symbol = *(str + i);
	}
	return (i);
}

int ft_printf(const char *str, ...)
{
	size_t count;
	size_t size;
	va_list args;
	char *result;

	result = (char *)str;
	va_start(args, str);
	size = 0;
	while (*str)
	{
		if (*str != '%')
		{
			size++;
			str++;
		}
		else
		{
			size += get_arg_size(str, args);
			str += get_arg_len(str);
		}
	}
	va_end(args);
	result = get_result_line(result, size);
	ft_lstclear(&g_list_args, free_content);
	if (result == 0)
		return (-1);
	count = 0;
	while (count < size)
		ft_putchar_fd(*(result + count++), 1);
	free(result);
	return ((int)size);
}
