#include "minishell.h"

bool	at_eof(t_token_kind kind)
{
	return (kind == TK_EOF);
}
