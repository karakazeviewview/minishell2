#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (dst == NULL || src == NULL)
	{
		return (NULL);
	}
	while (dst[i] != '\0')
	{
		i++;
	}
	while (j < n)
	{
		dst[i] = src[j];
		i += 1;
		j += 1;
	}
	dst[i] = '\0';
	return (dst);
}
