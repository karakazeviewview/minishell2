#include "minishell.h"

t_minishell	g_minishell;

static void	append_num(char **new_word, unsigned int num)
{
	if (num == 0)
	{
		add_character(new_word, '0');
		return ;
	}
	if ((num / 10) != 0)
	{
		append_num(new_word, num / 10);
	}
	add_character(new_word, '0' + (num % 10));
}

void	append_variable(char **new_word, char **rest, char *current_word)
{
	char	*value;
	char	*variable_name;

	value = NULL;
	variable_name = NULL;
	current_word++;
	while (is_alnum_underscore(*current_word))
	{
		add_character(&variable_name, *current_word);
		current_word++;
		if (*current_word == '\0')
			break ;
	}
	*rest = current_word;
	value = get_env(g_minishell.env, variable_name);
	free(variable_name);
	if (value == NULL)
		return ;
	while (*value != '\0')
	{
		add_character(new_word, *value);
		value++;
	}
}

void	append_special_param(char **new_word, char **rest,
		char *current_word)
{
	if (current_word == NULL)
	{
		return ;
	}
	current_word += 2;
	append_num(new_word, g_minishell.last_status);
	*rest = current_word;
}
