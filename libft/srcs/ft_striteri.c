#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;
	size_t			len;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	len = ft_strlen(s);
	if (UINT_MAX < len)
		return ;
	while (i < len)
	{
		f(i, &s[i]);
		i += 1;
	}
	return ;
}
