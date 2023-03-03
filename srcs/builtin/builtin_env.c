#include "minishell.h"

int	builtin_env(char **argv)
{
	t_env	*cur;

	(void)argv;
	cur = g_minishell.env;
	while (cur)
	{
		if (cur->value)
		{
			ft_putstr_fd(cur->name, STDOUT_FILENO);
			ft_putchar_fd('=', STDOUT_FILENO);
			ft_putstr_fd(cur->value, STDOUT_FILENO);
			ft_putchar_fd('\n', STDOUT_FILENO);
		}
		cur = cur->next;
	}
	ft_putstr_fd("_=/usr/bin/env\n", STDOUT_FILENO);
	return (0);
}
