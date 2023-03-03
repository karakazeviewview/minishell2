#include "minishell.h"

int	env_unset(t_env *env, char *name)
{
	t_env	*banp;
	t_env	*cur;

	banp = envnew();
	banp->next = env;
	cur = env;
	if (name == NULL || !is_identifier(name))
		return (-1);
	while (cur)
	{
		if (ft_strcmp(cur->name, name) == 0)
		{
			banp->next = cur->next;
			free(cur->name);
			free(cur->value);
			free(cur);
			return (0);
		}
		banp = banp->next;
		cur = cur->next;
	}
	return (0);
}

void	add_env(t_env *env, char *name, char *value)
{
	t_env	*env_n;

	if (name == NULL || !is_identifier(name))
	{
		perror("export not a valid identifer");
	}
	env_n = envnew();
	env_n->name = ft_strdup(name);
	if (value != NULL)
	{
		env_n->value = ft_strdup(value);
	}
	else
	{
		env_n->value = NULL;
	}
	add_back(&env, env_n);
}

char	*get_env(t_env *env, char *name)
{
	while (env)
	{
		if (ft_strcmp(env->name, name) == 0)
			return (env->value);
		env = env->next;
	}
	return (NULL);
}

void	env_free(t_env *env)
{
	t_env	*tmp;

	tmp = NULL;
	while (env)
	{
		if (tmp != NULL)
			free(tmp);
		if (env != NULL)
		{
			if (env->name)
				free(env->name);
			if (env->value)
				free(env->value);
			tmp = env;
		}
		env = env->next;
	}
	if (tmp)
		free(tmp);
}
