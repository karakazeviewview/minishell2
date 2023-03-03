#include "minishell.h"

static void	list_last_token(t_token **rest, t_token *token)
{
	if (token == NULL)
	{
		return ;
	}
	while (token->next != NULL)
	{
		token = token->next;
	}
	*rest = token;
}

void	append_args(t_token **args, t_token *add_token)
{
	t_token	*head_p;

	head_p = *args;
	if (add_token == NULL)
	{
		fatal_error("token_dup");
	}
	if (*args == NULL)
	{
		*args = add_token;
		return ;
	}
	list_last_token(args, *args);
	(*args)->next = add_token;
	*args = head_p;
}
