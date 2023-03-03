#include "minishell.h"

static bool	is_break(char c)
{
	if (is_blank(c))
	{
		return (true);
	}
	else if (is_meta_character(c))
	{
		return (true);
	}
	return (false);
}

static void	increment_until_quote(char **rest, char *line, char quote)
{
	line++;
	while (*line != quote)
	{
		if (*line == '\0')
		{
			if (quote == SINGLE_QUOTE_CHAR)
			{
				tokenize_error("Unclosed single quote", &line, line);
			}
			else if (quote == DOUBLE_QUOTE_CHAR)
			{
				tokenize_error("Unclosed double quote", &line, line);
			}
		}
		line++;
	}
	line++;
	*rest = line;
}

t_token	*new_token_type_word(char **rest, char *line)
{
	const char	*start_p;
	char		*word;

	start_p = line;
	word = NULL;
	while (*line)
	{
		if (is_break(*line))
			break ;
		else if (*line == SINGLE_QUOTE_CHAR || *line == DOUBLE_QUOTE_CHAR)
			increment_until_quote(&line, line, *line);
		else
			line++;
	}
	word = ft_strndup(start_p, line - start_p);
	if (word == NULL)
		fatal_error("strndup");
	else
	{
		*rest = line;
		return (new_token(TK_WORD, word));
	}
	tokenize_error("Unexpected Token", &line, line);
	return (NULL);
}
