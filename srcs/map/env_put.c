#include "minishell.h"

static int	env_not_value(char *string, bool e_value)
{
	int		result;
	char	*name;

	result = 0;
	name = NULL;
	result = env_put2(&name, string, e_value);
	result = env_set(name, NULL);
	free(name);
	return (result);
}

static int	env_exist_value(char *string, char *end)
{
	int		result;
	char	*name;
	char	*value;

	result = 0;
	value = NULL;
	name = ft_strndup(string, end - string);
	if (name == NULL)
		fatal_error("ft_strndup");
	end++;
	if (*end != '\0')
	{
		value = ft_strdup(end);
		if (value == NULL)
			fatal_error("ft_strndup");
	}
	result = env_set(name, value);
	free(name);
	free(value);
	return (result);
}

int	env_put(char *string, bool e_value)
{
	int		result;
	char	*name_end;

	result = 0;
	if (string == NULL)
		return (-1);
	name_end = ft_strchr(string, '=');
	if (name_end == NULL)
	{
		result = env_not_value(string, e_value);
	}
	else
	{
		result = env_exist_value(string, name_end);
	}
	return (result);
}
