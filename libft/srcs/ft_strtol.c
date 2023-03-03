#include "libft.h"

static unsigned char	charmap(char c)
{
	char	chr;

	chr = ft_toupper(c);
	if ('0' <= chr && chr <= '9')
		return (chr - '0');
	if ('A' <= chr && chr <= 'Z')
		return (chr - 'A' + 10);
	return (127);
}

static int	getbase(const char **nptr, int base)
{
	const char	*ptr;

	ptr = *nptr;
	if ((base == 0 || base == 16) && *ptr == '0')
	{
		if (*(++ptr) == 'x' && (++(ptr)))
			base = 16;
		else if (*ptr == '0')
			base = 8;
		else
			base = 10;
		*nptr = ptr;
	}
	return (base);
}

int	check_negative_and_jump_space(const char **rest, const char *nptr)
{
	while (ft_iswspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr++ == '-')
		{
			*rest = nptr;
			return (1);
		}
	}
	*rest = nptr;
	return (0);
}

long	ft_strtol(const char *nptr, char **endptr, int base)
{
	long	result;
	int		neg;
	char	digit;

	if (base < 0 || 36 < base)
		return (0);
	result = 0;
	neg = check_negative_and_jump_space(&nptr, nptr);
	base = getbase(&nptr, base);
	digit = charmap(*nptr++);
	while (digit < base)
	{
		result = (result * base) + digit;
		if (result < 0)
		{
			if (endptr)
				*endptr = (char *)nptr;
			return (LONG_MAX + neg);
		}
	}
	if (endptr)
		*endptr = (char *)nptr;
	return (result + (result * -2 * neg));
}
