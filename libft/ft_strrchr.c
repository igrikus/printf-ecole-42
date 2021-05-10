#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*result;

	result = 0;
	while (*s)
	{
		if (*s == (char) c)
			result = ((char *) s);
		s++;
	}
	if (*s == c)
		result = ((char *) s);
	return (result);
}
