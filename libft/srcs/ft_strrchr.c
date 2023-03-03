#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t				i;
	size_t				max;
	unsigned char		chr;
	const char			*p;

	i = 0;
	max = ft_strlen(s);
	chr = (unsigned char)c;
	p = 0;
	if (chr == '\0')
		return ((char *)&s[max]);
	while (s[i] != '\0')
	{
		if (s[i] == chr)
			p = &s[i];
		i += 1;
	}
	return ((char *)p);
}
