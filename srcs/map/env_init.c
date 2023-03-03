#include "minishell.h"

t_minishell	g_minishell;

void	env_pwdinit(t_env *env)
{
	char	cwd[PATH_MAX];
	char	*current_pwd_value;

	getcwd(cwd, PATH_MAX);
	current_pwd_value = get_env(env, "PWD");
	if (ft_strcmp(cwd, current_pwd_value) != 0)
	{
		if (env_unset(env, "PWD") < 0)
		{
			fatal_error("env_unset");
		}
		add_env(env, "PWD", current_pwd_value);
	}
}

void	assign_list(t_env *env, char *name, char *value)
{
	if (!env)
		return ;
	env->name = name;
	env->value = value;
}

void	create_list(t_env *env, char *ev)
{
	char	*name;
	char	*value;
	char	*tmp;

	tmp = ft_strchr(ev, '=');
	name = ft_strndup(ev, tmp - ev);
	value = ft_strdup(tmp + 1);
	if (tmp == NULL || name == NULL || value == NULL)
		perror("error");
	assign_list(env, name, value);
}

void	env_list_init(t_env *env, char **ev, size_t x)
{
	size_t	i;

	i = 0;
	while (i < x)
	{
		create_list(env, ev[i]);
		env = env->next;
		i++;
	}
}

void	env_init(void)
{
	extern char	**environ;
	t_env		*env_list;
	size_t		i;
	size_t		x;

	i = 0;
	x = 1;
	while (environ[i])
		i++;
	env_list = envnew();
	while (x < i)
	{
		add_back(&env_list, envnew());
		x++;
	}
	env_list_init(env_list, environ, i);
	g_minishell.env = env_list;
	if (get_env(env_list, "OLDPWD") == NULL)
		add_env(env_list, "OLDPWD", NULL);
	if (get_env(env_list, "SHLVL") == NULL)
		add_env(env_list, "SHLVL", "1");
	env_pwdinit(env_list);
}
