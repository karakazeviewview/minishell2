#include "minishell.h"

t_minishell	g_minishell;

int	return_buildin_error(void)
{
	builtin_error("cd", NULL, "HOME not set");
	return (1);
}

char	*set_oldpwd(void)
{
	char	*old_pwd;

	old_pwd = get_env(g_minishell.env, "PWD");
	if (get_env(g_minishell.env, "OLDPWD") != NULL)
		env_unset(g_minishell.env, "OLDPWD");
	add_env(g_minishell.env, "OLDPWD", old_pwd);
	return (old_pwd);
}
