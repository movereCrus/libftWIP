/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirus <kirus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:46:56 by kirus             #+#    #+#             */
/*   Updated: 2021/10/17 23:20:11 by kirus            ###   ########.fr       */
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

char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*news;
	unsigned int	i;

	i = 0;
	news = (char *)malloc(st_strlen(s1) + st_strlen(s2) + 1);
	if (news == NULL)
		return (NULL);
	while (*s1 != '\0')
	{
		news[i] = *s1;
		i++;
		s1++;
	}
	while (*s2 != '\0')
	{
		news[i] = *s2;
		i++;
		s2++;
	}
	news[i] = '\0';
	return (news);
}
