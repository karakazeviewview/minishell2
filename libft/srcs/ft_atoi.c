/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 04:59:22 by mmatsuo           #+#    #+#             */
/*   Updated: 2023/03/04 04:59:23 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c);
static int	change_format(const char *str, int sign);

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (ft_isspace(str[i]) == 1)
		i += 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i += 1;
	}
	num = change_format(&str[i], sign);
	return (num);
}

static int	ft_isspace(int c)
{
	if ((9 <= c && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

static int	change_format(const char *str, int sign)
{
	int			i;
	long long	num;

	i = 0;
	num = 0;
	while (ft_isdigit(str[i]) == 1)
	{
		if (num <= ((LONG_MAX - (str[i] - '0')) / 10))
			num = (num * 10) + (str[i] - '0');
		else
		{
			if (sign == -1)
				return ((int)LONG_MIN);
			else
				return ((int)LONG_MAX);
		}
		i += 1;
	}
	num *= (long long )sign;
	return ((int)num);
}
