#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			len;
	char			*str;

	if (s == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	str = ft_strdup(s);
	if (str == NULL)
		return (NULL);
	if (f != NULL || len <= UINT_MAX)
	{
		while (i < len)
		{
			str[i] = f(i, str[i]);
			i += 1;
		}
	}
	return (str);
}
