#include "minishell.h"

t_env	*envlast(t_env *lst)
{
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	add_back(t_env **lst, t_env *new)
{
	t_env	*last;

	if (*lst)
	{
		last = envlast(*lst);
		last->next = new;
	}
	else
		*lst = new;
}

t_env	*envnew(void)
{
	t_env	*elt;

	elt = malloc(sizeof(t_env) * 1);
	if (elt == NULL)
		return (NULL);
	elt->next = NULL;
	return (elt);
}
