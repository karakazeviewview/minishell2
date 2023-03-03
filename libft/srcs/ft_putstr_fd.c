#include "libft.h"

void	ft_putstr_fd(const char *s, int fd)
{
	size_t	len;

	if (s == NULL)
		(void)write(fd, "(null)", sizeof(char) * 6);
	else
	{
		len = ft_strlen(s);
		(void)write(fd, s, len);
	}
	return ;
}
