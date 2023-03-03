#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	i;
	char	*temp;

	i = 0;
	temp = (char *)ft_calloc(n + 1, sizeof(char));
	if (temp == NULL)
	{
		return (NULL);
	}
	while (i < n)
	{
		temp[i] = s1[i];
		i += 1;
	}
	return (temp);
}
