#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	len;

	if (lst == 0)
		return (0);
	len = 1;
	while (lst->next)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}
