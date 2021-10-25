/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirus <kirus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 23:11:16 by kirus             #+#    #+#             */
/*   Updated: 2021/10/25 01:49:34 by kirus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	eos;
	size_t	len;
	size_t	ctr;

	if (size == 0)
		return (ft_strlen(src));
	eos = ft_strlen(dest);
	if (size < eos)
		len = size + ft_strlen(src);
	else
		len = eos + ft_strlen(src);
	ctr = 0;
	while (ctr < size - 1 && eos < size - 1 && src[ctr] != '\0')
	{
		dest[eos] = src[ctr];
		ctr++;
		eos++;
	}
	dest[eos] = '\0';
	return (len);
}
