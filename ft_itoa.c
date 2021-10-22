/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirus <kirus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:00:48 by kirus             #+#    #+#             */
/*   Updated: 2021/10/22 22:07:48 by kirus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*st_conv(char *str, int n, int l)
{
	int	i;

	i = l;
	if (n == 0)
		str = "0";
	else if (n == -2147483648)
		str = "-2147483648";
	else
	{
		if (n / 10 > 0)
			str = st_conv(str, n / 10, --l);
		n %= 10;
		str[i] = n + 48;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		t;
	int		l;
	char	*str;

	l = 0;
	t = n;
	if (n < 0 && n != -2147483648)
		t = -n;
	while (t > 0 && n != -2147483648)
	{
		t /= 10;
		l++;
	}
	str = (char *)malloc((l + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n < 0 && n != -2147483648)
	{
		str[0] = '-';
		n = -n;
		str = st_conv(str, n, l);
	}
	else
		str = st_conv(str, n, --l);
	return (str);
}
