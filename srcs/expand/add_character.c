#include "minishell.h"

void	add_character(char **word, char c)
{
	size_t	size;
	char	*temp;

	size = 2;
	temp = NULL;
	if (*word != NULL)
	{
		size += ft_strlen(*word);
		temp = malloc(size * sizeof(char));
		if (temp == NULL)
		{
			fatal_error("malloc");
		}
		ft_strlcpy(temp, *word, size);
		free(*word);
	}
	else
	{
		temp = malloc(size * sizeof(char));
		if (temp == NULL)
			fatal_error("malloc");
	}
	temp[size - 2] = c;
	temp[size - 1] = '\0';
	*word = temp;
}
