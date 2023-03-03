#include "minishell.h"

char	*create_path(char *word)
{
	char	*path;

	path = NULL;
	if (ft_strchr(word, '/') == NULL)
	{
		path = search_path(word);
		if (path == NULL)
		{
			error_message(word, "command not found", 127);
		}
	}
	else
	{
		path = ft_strdup(word);
		if (path == NULL)
		{
			error_message(word, "command not found", 127);
		}
	}
	return (path);
}
