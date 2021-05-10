#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*result;
	unsigned long	i;

	i = (unsigned long) count * (unsigned long) size;
	result = malloc(i);
	if (result)
	{
		ft_bzero(result, i);
		return (result);
	}
	return (0);
}
