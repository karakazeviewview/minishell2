#include "minishell.h"

bool	is_alpha_underscore(const char c)
{
	return (ft_isalpha(c) || c == '_');
}

bool	is_alnum_underscore(const char c)
{
	return (ft_isalnum(c) || c == '_');
}

bool	is_variable(const char *str)
{
	return (str[0] == '$' && is_alpha_underscore(str[1]));
}

bool	is_special_parameter(const char *str)
{
	return (str[0] == '$' && str[1] == '?');
}
