#include "minishell.h"

t_minishell	g_minishell;

int	check_signal(void)
{
	if (g_minishell.sig == 0)
	{
		return (0);
	}
	else if (g_minishell.sig == SIGINT)
	{
		g_minishell.sig = 0;
		g_minishell.readline_interrupted = true;
		rl_replace_line("", 0);
		rl_done = 1;
	}
	return (0);
}
