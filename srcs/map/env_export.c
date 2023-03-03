#include "minishell.h"

t_minishell	g_minishell;

t_env	*item_new(char *name, char *value)
{
	t_env	*item;

	item = malloc(1 * sizeof(t_env));
	if (item == NULL)
		fatal_error("calloc");
	item->name = name;
	item->value = value;
	item->next = NULL;
	return (item);
}

int	env_set2(const char *name, const char *value)
{
	t_env	*new_env;

	new_env = NULL;
	if (value == NULL)
	{
		new_env = item_new(ft_strdup(name), NULL);
		if (new_env->name == NULL)
			fatal_error("strdup");
	}
	else
	{
		new_env = item_new(ft_strdup(name), ft_strdup(value));
		if (new_env->name == NULL || new_env->value == NULL)
			fatal_error("strdup");
	}
	new_env->next = g_minishell.env;
	g_minishell.env = new_env;
	return (0);
}

t_env	*search_env_name(t_env *env, const char *name)
{
	t_env	*cur;

	cur = env;
	while (cur)
	{
		if (ft_strcmp(cur->name, name) == 0)
			break ;
		cur = cur->next;
	}
	return (cur);
}

int	env_set(const char *name, const char *value)
{
	t_env	*cur;

	if (name == NULL || !is_identifier(name))
		return (-1);
	cur = search_env_name(g_minishell.env, name);
	if (cur)
	{
		if (cur->value != NULL)
			free(cur->value);
		if (value == NULL)
			cur->value = NULL;
		else
		{
			cur->value = ft_strdup(value);
			if (cur->value == NULL)
				fatal_error("strdup");
		}
	}
	else
		return (env_set2(name, value));
	return (0);
}

int	env_put2(char **value, char *string, bool e_value)
{
	if (!e_value)
		return (-1);
	if (string != NULL)
	{
		*value = ft_strdup(string);
		if (*value == NULL)
			fatal_error("strdup");
	}
	else
	{
		return (-1);
	}
	return (0);
}
