#include "minishell.h"

t_token	*new_token(t_token_kind kind, char *word)
{
	t_token	*new_token;

	new_token = ft_calloc(1, sizeof(t_token));
	if (new_token == NULL)
	{
		fatal_error("calloc");
	}
	new_token->word = word;
	new_token->kind = kind;
	new_token->next = NULL;
	return (new_token);
}
