/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirus <kirus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:00:48 by kirus             #+#    #+#             */
/*   Updated: 2021/10/24 02:29:48 by kirus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_conv(char *str, int n)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = -1;
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		str[i++] = (n % 10) + 48;
		n /= 10;
	}
	str[i] = '\0';
	while (++j < i / 2)
	{
		tmp = str[j];
		str[j] = str[i - 1 - j];
		str[i - 1 - j] = tmp;
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
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		t = -n;
	while (t > 0)
	{
		t /= 10;
		l++;
	}
	str = (char *)malloc((l + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str = ft_conv(str, n);
	if (n < 0)
		return (ft_strjoin("-", str));
	return (str);
}
