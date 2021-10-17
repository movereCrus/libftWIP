/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirus <kirus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 00:14:25 by kirus             #+#    #+#             */
/*   Updated: 2021/10/17 14:47:08 by kirus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	int	ptr1;
	int	ptr2;

	ptr1 = 0;
	ptr2 = 0;
	if (*to_find == 0)
		return ((char *)str);
	while (str[ptr1] != '\0' && len > 0)
	{
		while (to_find[ptr2] != '\0' && (to_find[ptr2] == str[ptr1]) && len > 0)
		{
			ptr2++;
			ptr1++;
			len--;
			if (to_find[ptr2] == '\0' && len >= 0)
				return ((char *)&str[ptr1 - ptr2]);
		}
		ptr2 = 0;
		ptr1++;
		len--;
	}
	return (NULL);
}
