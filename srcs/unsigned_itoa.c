#include "../includes/ft_printf.h"

static char	*get_malloc_array(int size)
{
	char	*array;

	array = get_malloc_result(size);
	if (array == 0)
		return (0);
	return (array);
}

static void	make_all_job(char *result, unsigned int n, int size)
{
	char			symbol;
	unsigned int	modulo;

	while (n != 0)
	{
		modulo = n % 10;
		symbol = (char)(modulo + '0');
		*(result + size - 1) = symbol;
		n /= 10;
		size--;
	}
}

char	*ft_unsigned_itoa(unsigned int n)
{
	char	*result;
	int		size;

	size = get_unsigned_num_len(n);
	result = get_malloc_array(size);
	if (result == 0)
		return (0);
	if (n == 0)
	{
		*result = '0';
		*(result + 1) = 0;
		return (result);
	}
	make_all_job(result, n, size);
	*(result + size) = 0;
	return (result);
}
