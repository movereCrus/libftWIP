/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirus <kirus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:17:14 by kirus             #+#    #+#             */
/*   Updated: 2021/10/17 23:20:13 by kirus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char				*subs;
	unsigned int		i;

	i = 0;
	subs = (char *)malloc(len + 1);
	if (subs == NULL)
		return (NULL);
	while (len > 0 && s[start + i] != '\0')
	{
		subs[i] = s[start + i];
		i++;
		len--;
	}
	subs[i] = '\0';
	return (subs);
}
