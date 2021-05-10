#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;
	size_t	haystack_len;

	needle_len = ft_strlen(needle);
	haystack_len = ft_strlen(haystack);
	if (needle_len == 0)
		return ((char *)haystack);
	if (haystack_len == 0)
		return (0);
	if (len == 0)
		return (0);
	i = 0;
	while (i <= len - needle_len && i <= haystack_len)
	{
		if ((haystack[0] == needle[0])
			&& (ft_strncmp(haystack, needle, needle_len) == 0))
			return ((char *)haystack);
		haystack++;
		i++;
	}
	return (0);
}
