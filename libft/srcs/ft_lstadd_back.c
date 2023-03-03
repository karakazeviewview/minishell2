#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	if (lst[0] == NULL)
		lst[0] = new;
	else
		ft_lstlast(lst[0])->next = new;
	return ;
}
