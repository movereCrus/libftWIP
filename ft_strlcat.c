/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirus <kirus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 23:11:16 by kirus             #+#    #+#             */
/*   Updated: 2021/10/24 00:35:52 by kirus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	st_strlen(const char *arr)
{
	size_t	c;

	c = 0;
	while (arr[c] != '\0')
		c++;
	return (c);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	eos;
	size_t	len;
	size_t	ctr;

	if (size == 0)
		return (st_strlen(src));
	eos = st_strlen(dest);
	if (size < eos)
		len = size + st_strlen(src);
	else
		len = eos + st_strlen(src);
	ctr = 0;
	while (ctr < size - 1 && eos < size - 1 && src[ctr] != '\0')
	{
		dest[eos] = src[ctr];
		ctr++;
		eos++;
	}
	return (len);
}
