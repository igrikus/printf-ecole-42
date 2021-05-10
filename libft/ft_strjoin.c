#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*result;
	unsigned int	s1_len;
	unsigned int	s2_len;
	unsigned int	total_len;

	if (s1 == 0 || s2 == 0)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	total_len = s1_len + s2_len + 1;
	result = malloc(total_len + 1);
	if (result == 0)
		return (0);
	while (*s1)
		*(result++) = *(s1++);
	*result = 0;
	result -= s1_len;
	ft_strlcat(result, s2, total_len);
	return (result);
}
