/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirus <kirus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:42:23 by kirus             #+#    #+#             */
/*   Updated: 2021/10/24 03:01:13 by kirus            ###   ########.fr       */
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

char	*ft_strdup(const char *str)
{
	char	*dest;

	dest = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	st_strcpy(dest, str);
	return (dest);
}
