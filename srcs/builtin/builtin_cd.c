#include "minishell.h"

t_minishell	g_minishell;

bool	consume_path(char **rest, char *path, char *elm)
{
	size_t	elm_len;

	elm_len = ft_strlen(elm);
	if (ft_strncmp(path, elm, elm_len) == 0)
	{
		if (path[elm_len] == '\0' || path[elm_len] == '/')
		{
			*rest = path + elm_len;
			return (true);
		}
	}
	return (false);
}

void	delete_last_elm(char *path)
{
	char	*start;
	char	*last_slash_ptr;

	start = path;
	last_slash_ptr = NULL;
	while (*path)
	{
		if (*path == '/')
			last_slash_ptr = path;
		path++;
	}
	if (last_slash_ptr != start)
		*last_slash_ptr = '\0';
}

void	append_path_elm(char *dst, char **rest, char *src)
{
	size_t	elm_len;

	elm_len = 0;
	while (src[elm_len] && src[elm_len] != '/')
		elm_len++;
	if (dst[ft_strlen(dst) - 1] != '/')
		ft_strlcat(dst, "/", PATH_MAX);
	ft_strncat(dst, src, elm_len);
	*rest = src + elm_len;
}

char	*resolve_pwd(char *oldpwd, char *path)
{
	char	newpwd[PATH_MAX];
	char	*dup;

	if (*path == '/' || oldpwd == NULL)
		ft_strlcpy(newpwd, "/", PATH_MAX);
	else
		ft_strlcpy(newpwd, oldpwd, PATH_MAX);
	while (*path)
	{
		if (*path == '/')
			path++;
		else if (consume_path(&path, path, "."))
			;
		else if (consume_path(&path, path, ".."))
			delete_last_elm(newpwd);
		else
			append_path_elm(newpwd, &path, path);
	}
	dup = ft_strdup(newpwd);
	if (dup == NULL)
		fatal_error("strdup");
	return (dup);
}

int	builtin_cd(char **argv)
{
	char	*home;
	char	*oldpwd;
	char	path[PATH_MAX];
	char	*newpwd;

	oldpwd = set_oldpwd();
	if (argv[1] == NULL)
	{
		home = get_env(g_minishell.env, "HOME");
		if (home == NULL)
			return (return_buildin_error());
		ft_strlcpy(path, home, PATH_MAX);
	}
	else
		ft_strlcpy(path, argv[1], PATH_MAX);
	if (chdir(path) < 0)
		return (return_buildin_error());
	newpwd = resolve_pwd(oldpwd, path);
	if (get_env(g_minishell.env, "PWD") != NULL)
		env_unset(g_minishell.env, "PWD");
	add_env(g_minishell.env, "PWD", newpwd);
	free(newpwd);
	return (0);
}
