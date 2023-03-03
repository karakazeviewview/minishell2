#include "minishell.h"

t_minishell	g_minishell;

void	tokenize_error(char *location, char **rest, char *line)
{
	g_minishell.syntax_error = true;
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd("syntax error near unexpected character `", STDERR_FILENO);
	ft_putchar_fd(*line, STDERR_FILENO);
	ft_putstr_fd("' in ", STDERR_FILENO);
	ft_putstr_fd(location, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	while (*line != '\0')
	{
		line++;
	}
	*rest = line;
}

void	parse_error(const char *location, t_token **rest, t_token *token)
{
	g_minishell.syntax_error = true;
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd("syntax error near unexpected token `", STDERR_FILENO);
	ft_putstr_fd(token->word, STDERR_FILENO);
	ft_putstr_fd("' in ", STDERR_FILENO);
	ft_putstr_fd(location, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	while (token && !at_eof(token->kind))
	{
		token = token->next;
	}
	*rest = token;
}

void	fatal_error(const char *message)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd("Fatal Error: ", STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	exit(1);
}

void	assert_error(const char *message)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd("Assert Error: ", STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	exit (255);
}

void	error_message(const char *location, const char *message, int status)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(location, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	exit(status);
}
