#include "../includes/ft_printf.h"

char *get_result_line(const char *str, size_t size)
{
	t_list *temp;
	int arg_len;
	char *result;

	result = malloc(sizeof(char) * (size + 1));
	ft_memset(result, 0, size + 1);
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
			ft_strlcat(result, (const char *) temp->content, size + 1);
			result += ft_strlen((const char *) temp->content);
			temp = temp->next;
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
		else if (symbol == 's')
			return (parse_str(str, args));
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
	size_t result_len;
	size_t i;
	va_list args;
	char *result;

	result = (char *)str;
	va_start(args, str);
	i = 0;
	while (*str)
	{
		if (*str != '%')
		{
			i++;
			str++;
		}
		else if (*str == '%' && *(str + 1) == '%')
		{
			i++;
			str += 2;
		}
		else
		{
			i += get_arg_size(str, args);
			str += get_arg_len(str);
		}
	}
	va_end(args);
	result = get_result_line(result, i);
	ft_lstclear(&list_args, free_content);
	if (result == 0)
		return (-1);
	ft_putstr_fd((char *)result, 1);
	result_len = ft_strlen(result);
	free(result);
	return ((int)result_len);
}

//int main() {
//	ft_printf("%32s", "abc");
//	write(1, "\n", 1);
//	printf("%32s", "abc");
//}
