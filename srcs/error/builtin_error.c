#include "minishell.h"

void	builtin_error(const char *func, const char *name, const char *err)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(func, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	if (name)
	{
		ft_putchar_fd('`', STDERR_FILENO);
		ft_putstr_fd(name, STDERR_FILENO);
		ft_putstr_fd("': ", STDERR_FILENO);
		ft_putstr_fd(err, STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
	}
}
