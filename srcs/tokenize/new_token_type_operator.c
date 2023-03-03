#include "minishell.h"

static bool	is_operator(char *str, const char *operator)
{
	return (ft_memcmp(str, operator, ft_strlen(operator)) == 0);
}

t_token	*new_token_type_operator(char **rest, char *line)
{
	char *const	operators_list[] = {
		"||", "&&", ";;", ">>", "<<", ">", "<", "|", "&", ";", "(", ")", "\n"};
	char		*operator;
	int			i;

	operator = NULL;
	i = 0;
	while (i < SIZE_OPERATORS_LIST)
	{
		if (is_operator(line, operators_list[i]))
		{
			operator = ft_strdup(operators_list[i]);
			if (operator == NULL)
				fatal_error("ft_strdup");
			else
			{
				*rest = line + ft_strlen(operator);
				return (new_token(TK_OPERATOR, operator));
			}
		}
		i += 1;
	}
	tokenize_error("Unexpected Token", &line, line);
	return (NULL);
}
