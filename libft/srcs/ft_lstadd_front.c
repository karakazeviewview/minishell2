#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	ft_lstlast(new)->next = lst[0];
	lst[0] = new;
	return ;
}
