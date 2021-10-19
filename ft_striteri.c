/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirus <kirus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:58:30 by kirus             #+#    #+#             */
/*   Updated: 2021/10/19 22:01:39 by kirus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	st_strlen(char const *arr)
{
	size_t	c;

	c = 0;
	while (arr[c] != '\0')
		c++;
	return (c);
}

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;
	int	len;

	len = st_strlen(s);
	i = len;
	while (len > 0)
	{
		f(len - i, s[len - i]);
		i--;
	}
}
