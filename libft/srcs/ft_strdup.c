#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	s1_len;
	char	*temp;

	s1_len = ft_strlen(s1);
	temp = (char *)ft_calloc(s1_len + 1, sizeof(char));
	if (temp == NULL)
		return (NULL);
	(void)ft_strlcpy(temp, s1, s1_len + 1);
	return (temp);
}
