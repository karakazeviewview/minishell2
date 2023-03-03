#include "minishell.h"

static size_t	env_strlen(t_env *env)
{
	size_t	size;

	size = 0;
	if (env->name != NULL)
	{
		size = ft_strlen(env->name);
	}
	if (env->value != NULL)
	{
		size += ft_strlen(env->value);
	}
	return (size);
}

static size_t	count_env(t_env *env)
{
	size_t	size;

	size = 0;
	while (env != NULL)
	{
		size += 1;
		env = env->next;
	}
	return (size);
}

char	*cat_env_name_value(t_env *env)
{
	char	*str;
	size_t	str_size;

	str_size = env_strlen(env);
	str = ft_calloc(str_size + 2, sizeof(char));
	if (str == NULL)
	{
		fatal_error("ft_calloc");
	}
	if (env->name != NULL)
	{
		ft_strlcpy(str, env->name, str_size + 2);
		ft_strlcat(str, "=", str_size + 2);
	}
	if (env->value != NULL)
	{
		ft_strlcat(str, env->value, str_size + 2);
	}
	return (str);
}

char	**create_env(t_env *env)
{
	char	**dst_head;
	char	**dst;
	size_t	env_size;
	size_t	i;

	dst_head = NULL;
	dst = NULL;
	env_size = count_env(env);
	i = 0;
	dst = ft_calloc(env_size + 1, sizeof(char *));
	if (dst == NULL)
	{
		fatal_error("ft_calloc");
	}
	dst_head = dst;
	while (i < env_size)
	{
		*dst = cat_env_name_value(env);
		dst++;
		env = env->next;
		i += 1;
	}
	return (dst_head);
}
