#include "minishell.h"

void	frees_argv(char **argv)
{
	char	**head_p;

	head_p = argv;
	while (*argv != NULL)
	{
		free(*argv);
		argv++;
	}
	free(*argv);
	free(head_p);
}

void	list_frees_token(t_token *token)
{
	t_token	*next_token;

	next_token = NULL;
	if (token == NULL)
	{
		return ;
	}
	while (token != NULL)
	{
		if (token->word != NULL)
		{
			free(token->word);
		}
		next_token = token->next;
		free(token);
		token = next_token;
	}
	free(token);
}

static void	list_frees_redirects(t_node *list)
{
	t_node	*next_node;

	next_node = NULL;
	if (list == NULL)
	{
		return ;
	}
	while (list != NULL)
	{
		list_frees_token(list->args);
		next_node = list->next;
		free(list);
		list = next_node;
	}
}

void	list_frees_command(t_node *list)
{
	t_node	*next_node;

	next_node = NULL;
	if (list == NULL)
	{
		return ;
	}
	while (list != NULL)
	{
		list_frees_token(list->args);
		list_frees_redirects(list->redirects);
		next_node = list->next;
		free(list);
		list = next_node;
	}
}

void	list_frees_node(t_node *node)
{
	t_node	*next_node;

	next_node = NULL;
	if (node == NULL)
	{
		return ;
	}
	while (node != NULL)
	{
		list_frees_command(node->command);
		next_node = node->next;
		free(node);
		node = next_node;
	}
}
