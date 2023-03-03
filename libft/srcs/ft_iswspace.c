#include "libft.h"

int	ft_iswspace(int wc)
{
	if (wc == ' ' || wc == '\t' || wc == '\n')
		return (1);
	return (0);
}
