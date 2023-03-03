#include "minishell.h"

void	append_redirects(t_node **redir, t_token *add_token,
		t_node_kind kind)
{
	if (add_token == NULL)
	{
		fatal_error("token_dup");
	}
	if (*redir == NULL)
	{
		*redir = new_node(kind);
		if (*redir == NULL)
		{
			fatal_error("new_node");
		}
		(*redir)->args = add_token;
		return ;
	}
	else
	{
		list_add_back(redir, add_token, kind);
	}
}
