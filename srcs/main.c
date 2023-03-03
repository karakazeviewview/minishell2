#include "minishell.h"

t_minishell	g_minishell;

void	execute_command(char *line)
{
	t_token	*token;
	t_node	*node;

	token = NULL;
	node = NULL;
	token = tokenize(line);
	if (token->kind == TK_EOF)
		;
	else if (g_minishell.syntax_error == true)
	{
		g_minishell.last_status = ERROR_TOKENIZE;
	}
	else
	{
		node = parse(token);
		node = expand(node);
		g_minishell.last_status = interpret(node);
		list_frees_node(node);
	}
	list_frees_token(token);
}

int	main(void)
{
	char	*line;

	line = NULL;
	rl_outstream = stderr;
	g_minishell.syntax_error = false;
	env_init();
	setup_signals();
	g_minishell.last_status = 0;
	while (1)
	{
		line = readline("minishell$ ");
		if (line == NULL)
		{
			break ;
		}
		if (ft_strlen(line))
		{
			add_history(line);
		}
		execute_command(line);
		free(line);
	}
	env_free(g_minishell.env);
	exit (g_minishell.last_status);
}

/*
void	execute_command(char *line)
{
	t_token	*token;
	t_node	*node;

	token = NULL;
	node = NULL;
	// printf("line == [%s]\n", line);
	token = tokenize(line);
	// printf("---------------------------------\n");
	// print_result_token(token, "Result tokenize();");
	if (token->kind == TK_EOF)
		;
	else if (g_minishell.syntax_error == true)
	{
		g_minishell.last_status = ERROR_TOKENIZE;
	}
	else
	{
		node = parse(token);
		// print_result_parse(node, "Result parse();");
		node = expand(node);
		// print_result_expand(node, "Result expand();  ");
		if (open_redir_file(node) < 0)
		{
			exit (ERROR_OPEN_REDIR);
		}
		// print_result_redirect(node);
		g_minishell.last_status = interpret(node);
		closes_redirect_file(node);
		list_frees_node(node);
	}
	list_frees_token(token);
}
*/
