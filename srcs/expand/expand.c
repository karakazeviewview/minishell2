#include "minishell.h"

static void	expand_redirects(t_node *redir)
{
	if (redir == NULL)
	{
		return ;
	}
	while (redir != NULL)
	{
		try_remove_quote(redir->args);
		redir = redir->next;
	}
}

t_node	*expand(t_node *node)
{
	t_node	*head_p;

	if (node == NULL)
	{
		return (NULL);
	}
	head_p = node;
	while (node != NULL)
	{
		try_remove_quote(node->command->args);
		expand_redirects(node->command->redirects);
		node = node->next;
	}
	return (head_p);
}
