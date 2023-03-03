#include <limits.h>
#include "minishell.h"

static void	make_path(char *target, const char *file_name, char *env_path,
		char *tail_p)
{
	if (tail_p != NULL)
	{
		ft_strncpy(target, env_path, tail_p - env_path);
	}
	else
	{
		ft_strlcpy(target, env_path, PATH_MAX);
	}
	ft_strlcat(target, "/", PATH_MAX);
	ft_strlcat(target, file_name, PATH_MAX);
}

char	*search_path(const char *file_name)
{
	char	*env_path;
	char	*tail_p;
	char	target[PATH_MAX];
	char	*dup;

	dup = NULL;
	env_path = getenv("PATH");
	while (env_path)
	{
		ft_bzero(target, PATH_MAX);
		tail_p = ft_strchr(env_path, ':');
		make_path(target, file_name, env_path, tail_p);
		if (access(target, X_OK) == 0)
		{
			dup = ft_strdup(target);
			if (dup == NULL)
				fatal_error("strdup");
			return (dup);
		}
		if (tail_p == NULL)
			return (NULL);
		env_path = tail_p + 1;
	}
	return (NULL);
}
