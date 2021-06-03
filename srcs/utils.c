#include "../includes/ft_printf.h"

size_t	get_num_len(int num)
{
	int	len;

	len = 1;
	while (num != 0)
	{
		num /= 10;
		if (num != 0)
			len++;
	}
	return (len);
}

char	*get_malloc_result(size_t max_len)
{
	char *result;

	result = malloc(sizeof(char) * (max_len + 1));
	if (result == 0)
		return (0);
	ft_memset(result, 0, max_len + 1);
	return (result);
}

void free_content(void *content)
{
	t_arg *arg;

	arg = (t_arg *) content;
	free(arg->str);
}

void fill_list(void *content, size_t content_len)
{
	t_list *new;

	if (ft_lstsize(list_args) == 0)
	{
		list_args = ft_lstnew(content);
		list_args->content_len = content_len;
	}
	else
	{
		new = ft_lstnew(content);
		new->content_len = content_len;
		ft_lstadd_back(&list_args, new);
	}
}
