#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long int	ln;
	char			c;

	ln = (long long int)n;
	if (ln == 0)
		ft_putchar_fd('0', fd);
	else
	{
		if (ln < 0)
		{
			ft_putchar_fd('-', fd);
			ln *= -1;
		}
		if (9 < ln)
		{
			ft_putnbr_fd(ln / 10, fd);
			ft_putnbr_fd(ln % 10, fd);
		}
		else
		{
			c = ln + '0';
			ft_putchar_fd(c, fd);
		}
	}
	return ;
}
