#include "libft.h"

size_t	ft_strclen(const char *s, const char c)
{
	size_t	len;

	len = 0;
	while (s[len] != c && s[len] != '\0')
	{
		len += 1;
	}
	if (s[len] == '\0')
	{
		return (0);
	}
	return (len);
}
