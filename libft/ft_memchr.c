#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int	i;

	i = 0;
	while (i < (int) n)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			return ((void *) s);
		i++;
		s++;
	}
	return (0);
}
