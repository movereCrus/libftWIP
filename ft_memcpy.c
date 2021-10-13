/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirus <kirus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 23:23:41 by kirus             #+#    #+#             */
/*   Updated: 2021/10/12 23:39:35 by kirus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	int				i;
	unsigned char	*src0;
	unsigned char	*dest0;

	src0 = (unsigned char *)src;
	dest0 = (unsigned char *)dest;
	i = 0;
	while (count-- > 0)
	{
		dest0[i] = src0[i];
		i++;
	}
	return (dest0);
}