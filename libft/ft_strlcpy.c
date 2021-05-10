#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	res;

	if (dst == 0 || src == 0)
		return (0);
	res = ft_strlen(src);
	if (dstsize == 0)
		return (res);
	i = 0;
	while (*src && (i < dstsize - 1))
	{
		*dst = *src;
		i++;
		dst++;
		src++;
	}
	*dst = 0;
	return (res);
}
