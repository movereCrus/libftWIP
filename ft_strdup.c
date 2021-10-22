/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirus <kirus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:42:23 by kirus             #+#    #+#             */
/*   Updated: 2021/10/22 22:10:00 by kirus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*st_strcpy(char *dest, const char *src)
{
	int	ctr;

	ctr = 0;
	while (*(src + ctr) != '\0')
	{
		*(dest + ctr) = *(src + ctr);
		ctr++;
	}
	*(dest + ctr) = '\0';
	return (dest);
}

static size_t	st_strlen(const char *arr)
{
	size_t	c;

	c = 0;
	while (arr[c] != '\0')
		c++;
	return (c);
}

char	*ft_strdup(const char *str)
{
	char	*dest;

	dest = (char *)malloc(st_strlen(str) + 1);
	if (dest == NULL)
		return (NULL);
	st_strcpy(dest, str);
	return (dest);
}
