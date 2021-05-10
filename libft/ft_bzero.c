#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	int	i;

	if (n == 0)
		return ;
	i = 0;
	while (i < (int) n)
	{
		*(unsigned char *) s = 0;
		i++;
		s++;
	}
}
