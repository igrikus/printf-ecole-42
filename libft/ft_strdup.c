#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*result;

	len = (int)ft_strlen(s1);
	result = malloc(len + 1);
	if (result == 0)
		return (0);
	while (*s1)
	{
		*result = *s1;
		result++;
		s1++;
	}
	*result = 0;
	return (result - len);
}
