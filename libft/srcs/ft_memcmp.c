#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_uc;
	unsigned char	*s2_uc;

	if (n == 0 || s1 == s2)
		return (0);
	i = 0;
	s1_uc = (unsigned char *)s1;
	s2_uc = (unsigned char *)s2;
	while (i < (n - 1))
	{
		if ((s1_uc[i] - s2_uc[i]) != 0)
			return (s1_uc[i] - s2_uc[i]);
		i += 1;
	}
	return (s1_uc[i] - s2_uc[i]);
}
