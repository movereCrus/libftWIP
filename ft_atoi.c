/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirus <kirus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:56:08 by kirus             #+#    #+#             */
/*   Updated: 2021/10/22 22:17:37 by kirus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	st_spaceskip(const char *str)
{
	int	pos;

	pos = 0;
	while (((int)*str < 14 && (int)*str > 8) || *str == ' ')
	{
		pos++;
		str++;
	}
	return (pos);
}

static int	st_evnumber(int neg, const char *str)
{
	int	num0;
	int	num1;

	num0 = (int)*str - 48;
	num1 = 0;
	while ((int)*str > 47 && (int)*str < 58)
	{
		if ((int)*(str + 1) > 47 && (int)*(str + 1) < 58)
		{
			num1 = (int)*(str + 1) - 48;
			num0 = num0 * 10 + num1;
		}
		str++;
	}
	if (neg > 0)
		num0 = -num0;
	return (num0);
}

int	ft_atoi(const char *str)
{
	int	neg;
	int	pos;

	neg = 0;
	pos = st_spaceSkip(str);
	str += pos;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg++;
		str++;
	}
	if (*str > 47 && *str < 58)
		neg = st_evnumber(neg, str);
	else
		return (0);
	return (neg);
}
