#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	(void)write(fd, &c, sizeof(char));
	return ;
}
