#include "minishell.h"

t_minishell	g_minishell;

bool	is_numeric(char *s)
{
	if (!ft_isdigit(*s))
		return (false);
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (false);
		s++;
	}
	return (true);
}

int	builtin_exit(char **argv)
{
	long	res;
	char	*arg;
	char	*endptr;

	if (argv[1] == NULL)
		exit(g_minishell.last_status);
	if (argv[2])
	{
		xperror("exit: too many arguments");
		return (1);
	}
	arg = argv[1];
	if (is_numeric(arg))
	{
		errno = 0;
		res = ft_strtol(arg, &endptr, 10);
		if (errno == 0 && *endptr == '\0')
		{
			exit((int)res);
		}
	}
	xperror("exit: numeric argument required");
	exit(255);
}
