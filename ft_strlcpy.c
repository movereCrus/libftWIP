/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirus <kirus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 00:22:19 by kirus             #+#    #+#             */
/*   Updated: 2021/10/14 01:11:51 by kirus            ###   ########.fr       */
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

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	ctr;

	if (size == 0)
		return (st_strlen(src));
	ctr = 0;
	while (ctr < size - 1 && src[ctr] != '\0')
	{
		dest[ctr] = src[ctr];
		ctr++;
	}
	dest[ctr] = '\0';
	while (src[ctr] != '\0')
		ctr++;
	return (ctr);
}
