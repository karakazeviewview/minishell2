#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;

	if (lst == NULL)
		return (0);
	i = 1;
	while (lst->next != NULL && i < INT_MAX)
	{
		lst = lst->next;
		i += 1;
	}
	if (i == INT_MAX && lst->next != NULL)
		return (-1);
	return (i);
}
