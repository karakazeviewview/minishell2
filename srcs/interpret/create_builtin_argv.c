#include "minishell.h"

char	**create_builtin_argv(t_token *args)
{
	char	*command;
	char	**argv;

	command = ft_strdup(args->word);
	if (command == NULL)
	{
		fatal_error("ft_strdup");
	}
	argv = create_argv(command, args);
	return (argv);
}
