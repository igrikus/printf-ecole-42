#include "../includes/ft_printf.h"

void free_content(void *content)
{
	free(content);
}

char *get_result_line(const char *str, size_t size)
{
	int arg_len;
	char *result;

	result = malloc(size + 1);
	if (result == 0)
		return (0);
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
			ft_strlcat(result, (const char *) list_args->content, size + 1);
			result += ft_strlen((const char *) list_args->content);
			list_args = list_args->next;
			str += arg_len;
		}
		else
			*(result++) = *(str++);
	}
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
//		else if (symbol == 's')
//			return (arse_str(str, args));
//		else if (symbol == 'c')
//			return (parse_char(str, args));
//		else if (symbol == 'p')
//			return (parse_pointer(str, args));
//		else if (symbol == 'u')
//			return (parse_unsigned(str, args));
//		else if (symbol == 'x' || symbol == 'X')
//			return (parse_hex(str, args));
		i++;
		symbol = *(str + i);
	}
	return (0);
}

int ft_printf(const char *str, ...)
{
	size_t i;
	size_t size;
	va_list args;
	char *result;

	va_start(args, str);
	size = 0;
	while (*(str + size))
	{
		i = 0;
		if (*(str + size) != '%')
			i++;
		else if (*(str + size) == '%' && *(str + size + 1) == '%')
			i += 2;
		else
			i = get_arg_size(str + size, args);
		size += i;
	}
	va_end(args);
	result = get_result_line(str, size);
	ft_lstclear(&list_args, free_content);
	if (result == 0)
		return (-1);
	ft_putstr_fd(result, 1);
	return ((int)ft_strlen(result));
}

int main() {
	ft_printf("hello %d\n", 42);
	//printf("%-6.4d\n", 10);
}
