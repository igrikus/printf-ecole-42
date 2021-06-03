#include "../includes/ft_printf.h"

char *concat_arg(char *result)
{
	char *arg;
	size_t count;

	arg = list_args->content;
	count = 0;
	while (count < list_args->content_len)
	{
		*(result + count) = *(arg + count);
		count++;
	}
	result += list_args->content_len;
	list_args = list_args->next;
	return (result);
}

char *get_result_line(const char *str, size_t size)
{
	t_list *temp;
	int arg_len;
	char *result;

	result = get_malloc_result(size);
	if (result == 0)
		return (0);
	temp = list_args;
	while (*str)
	{
		if (*str == '%' && *(str + 1) == '%')
		{
			*(result++) = '%';
			str += 2;
		}
		else if (*str == '%')
		{
			arg_len = get_arg_len(str);
			result = concat_arg(result);
			str += arg_len;
		}
		else
			*(result++) = *(str++);
	}
	list_args = temp;
	*result = 0;
	return (result - size);
}

size_t get_arg_size(const char *str, va_list args)
{
	int	i;
	char symbol;

	symbol = *str;
	i = 0;
	while (symbol)
	{
		if (symbol == 'd' || symbol == 'i')
			return (parse_int(str, args));
		else if (symbol == 's')
			return (parse_str(str, args));
		else if (symbol == 'c')
			return (parse_char(str, args));
//		else if (symbol == 'p')
//			return (parse_pointer(str, args));
		else if (symbol == 'u')
			return (parse_unsigned(str, args));
//		else if (symbol == 'x' || symbol == 'X')
//			return (parse_hex(str, args));
		i++;
		symbol = *(str + i);
	}
	return (0);
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
		else if (*str == '%' && *(str + 1) == '%')
		{
			size++;
			str += 2;
		}
		else
		{
			size += get_arg_size(str, args);
			str += get_arg_len(str);
		}
	}
	va_end(args);
	result = get_result_line(result, size);
	ft_lstclear(&list_args, free_content);
	if (result == 0)
		return (-1);
	count = 0;
	while (count < size)
		ft_putchar_fd(*(result + count++), 1);
	free(result);
	return ((int)size);
}

int main() {
	ft_printf("%c %10c", '0', '1');
	write(1, "\n", 1);
	printf("%c %10c", '0', '1');
}
