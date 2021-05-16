#include "../includes/printf.h"

void free_content(void *content)
{
	free(content);
}

void fill_list(void *content)
{
	t_list *new;

	if (ft_lstsize(list_args) == 0)
		list_args = ft_lstnew(content);
	else
	{
		new = ft_lstnew(content);
		ft_lstadd_back(&list_args, new);
	}
}
