#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	if (lst == NULL || lst[0] == NULL)
		return ;
	while (lst[0] != NULL)
	{
		next = lst[0]->next;
		ft_lstdelone(lst[0], del);
		lst[0] = next;
	}
	lst = NULL;
}
