#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_siz;
	size_t	calc_siz;
	char	*sub;

	if (s == NULL)
		return (NULL);
	s_siz = ft_strlen(s);
	calc_siz = 0;
	if (len <= 0 || s_siz <= start)
		return (ft_strdup(""));
	calc_siz = ft_strlen(&s[start]);
	if (len < calc_siz)
		calc_siz = len;
	sub = (char *)ft_calloc(calc_siz + 1, sizeof(char));
	if (sub == NULL)
		return (NULL);
	(void)ft_strlcpy(sub, &s[start], calc_siz + 1);
	return (sub);
}
