#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*s1_uc;
	unsigned char	*s2_uc;

	s1_uc = (unsigned char *)s1;
	s2_uc = (unsigned char *)s2;
	while (*s1_uc != '\0' && *s2_uc != '\0')
	{
		if ((*s1_uc - *s2_uc) != 0)
		{
			return (*s1_uc - *s2_uc);
		}
		s1_uc++;
		s2_uc++;
	}
	return (*s1_uc - *s2_uc);
}
