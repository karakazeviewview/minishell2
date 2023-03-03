#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_uc;
	unsigned char	*s2_uc;

	if (n == 0)
		return (0);
	i = 0;
	s1_uc = (unsigned char *)s1;
	s2_uc = (unsigned char *)s2;
	while (i < (n - 1))
	{
		if (s1_uc[i] == '\0' || s2_uc[i] == '\0')
			return (s1_uc[i] - s2_uc[i]);
		if ((s1_uc[i] - s2_uc[i]) != 0)
			return (s1_uc[i] - s2_uc[i]);
		i += 1;
	}
	return (s1_uc[i] - s2_uc[i]);
}
