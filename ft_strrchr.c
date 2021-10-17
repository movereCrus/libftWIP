/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwarlock <dwarlock@students.21-school.ru>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 23:23:41 by kirus             #+#    #+#             */
/*   Updated: 2021/10/12 23:23:41 by kirus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	p;

	p = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			p = i;
		i++;
		if (s[i] == '\0' && c == 0)
			p = i;
	}
	if (p == 0 && s[p] != c)
		return (NULL);
	return (s + p);
}
