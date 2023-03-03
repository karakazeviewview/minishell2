#include "minishell.h"

t_minishell	g_minishell;

void	print_allenv(void)
{
	t_env	*cur;

	cur = g_minishell.env;
	while (cur)
	{
		if (cur->name)
		{
			ft_putstr_fd("declare -x ", STDOUT_FILENO);
			ft_putstr_fd(cur->name, STDOUT_FILENO);
		}
		if (cur->value)
		{
			ft_putchar_fd('=', STDOUT_FILENO);
			ft_putchar_fd('\"', STDOUT_FILENO);
			ft_putstr_fd(cur->value, STDOUT_FILENO);
			ft_putchar_fd('\"', STDOUT_FILENO);
			ft_putchar_fd('\n', STDOUT_FILENO);
		}
		else
			ft_putchar_fd('\n', STDOUT_FILENO);
		cur = cur->next;
	}
}

int	builtin_export(char **argv)
{
	size_t	i;
	int		status;

	if (argv[1] == NULL)
	{
		print_allenv();
		return (0);
	}
	status = 0;
	i = 1;
	while (argv[i] != NULL)
	{
		if (env_put(argv[i], true) < 0)
		{
			builtin_error("export", argv[i], "not a valid identifier");
			status = 1;
		}
		i++;
	}
	return (status);
}
