#include "../includes/ft_printf.h"

//int get_arg_size(const char *str, void *param)
//{
//	int	i;
//	int	size;
//	char symbol;
//
//	symbol = *str;
//	i = 0;
//	size = 1;
//	while (symbol)
//	{
//		if (symbol == 'd' || symbol == 'i')
//			return (parse_int(str, (int*)param));
//		else if (symbol == 's')
//			return (arse_str(str, (char *)param));
//		else if (symbol == 'c')
//			return (parse_char(str, (char *)param));
//		else if (symbol == 'p')
//			return (parse_pointer(str, param));
//		else if (symbol == 'u')
//			return (parse_unsigned(str, (unsigned int *)param));
//		else if (symbol == 'x' || symbol == 'X')
//			return (parse_hex(str, (int *)param));
//		i++;
//		symbol = *(str + i);
//	}
//	return (0);
//}
//
//int ft_printf(const char *str, ...)
//{
//	int i;
//	int size;
//	va_list args;
//
//	va_start(args, str);
//	size = 0;
//	while (*str)
//	{
//		i = 0;
//		if (*str != '%')
//			i++;
//		else if (*str == '%' && *(str + 1) == '%')
//			i += 2;
//		else
//			i = get_arg_size(str, va_arg(args, void *));
//		size += i;
//		str += i;
//	}
//	va_end(args);
//}

int main() {
	//ft_printf("hello %d\n", 42);
	printf("%d\n", 50);

}
