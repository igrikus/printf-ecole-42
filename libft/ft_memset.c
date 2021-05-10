#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int		i;
	void	*temp;

	temp = b;
	i = 0;
	while (i < (int) len)
	{
		*(unsigned char *) b = c;
		b++;
		i++;
	}
	return (temp);
}
