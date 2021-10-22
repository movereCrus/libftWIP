/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirus <kirus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:36:56 by kirus             #+#    #+#             */
/*   Updated: 2021/10/22 22:10:41 by kirus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	st_strlen(char const *arr)
{
	size_t	c;

	c = 0;
	while (arr[c] != '\0')
		c++;
	return (c);
}

int	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		len;
	int		i;

	len = st_strlen(s);
	str = (char *)malloc((len + 1) * sizeof(char));
	i = len;
	while (i > 0)
	{
		str[len - i] = f(len - i, s[len - i]);
		i--;
	}
	return (str);
}
