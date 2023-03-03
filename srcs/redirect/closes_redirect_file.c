#include "minishell.h"

static void	closes_file(t_token *args)
{
	if (args == NULL)
	{
		return ;
	}
	while (args != NULL)
	{
		if (args->kind == TK_WORD)
		{
			if (close(args->file_fd) < 0)
			{
				assert_error("close");
			}
		}
		args = args->next;
	}
}

static void	close_target_command(t_node *command)
{
	t_node	*redir;

	redir = NULL;
	if (command == NULL)
	{
		return ;
	}
	redir = command->redirects;
	while (redir != NULL)
	{
		if (redir->kind == NODE_REDIR_IN)
		{
			closes_file(redir->args);
		}
		else if (redir->kind == NODE_REDIR_OUT)
		{
			closes_file(redir->args);
		}
		redir = redir->next;
	}
}

void	closes_redirect_file(t_node *node)
{
	if (node == NULL)
	{
		return ;
	}
	while (node != NULL)
	{
		close_target_command(node->command);
		node = node->next;
	}
}
