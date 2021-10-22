/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirus <kirus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:11:53 by kirus             #+#    #+#             */
/*   Updated: 2021/10/22 22:07:53 by kirus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void static	st_bzero(void *buf, size_t count)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)buf;
	while (count > 0)
	{
		*ptr = '\0';
		ptr++;
		count--;
	}
}

void	*ft_calloc(size_t len, size_t size)
{
	void	*m;

	m = malloc(len * size);
	if (m == NULL)
		return (NULL);
	st_bzero(m, len * size);
	return (m);
}
