/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirus <kirus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:36:12 by kirus             #+#    #+#             */
/*   Updated: 2021/10/24 01:03:39 by kirus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**st_freeall(char **str, size_t w)
{
	while (w > 0)
	{
		free(str[w]);
		w--;
	}
	free(str[0]);
	free(str);
	str = NULL;
	return (str);
}

static char	**st_strfill(char const *s, char c, char **str, size_t w)
{
	size_t	i;
	size_t	p;

	p = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
			{
				str[w][p] = s[i];
				p++;
				i++;
			}
			str[w][p] = '\0';
			p = 0;
			w++;
		}
		else
			i++;
	}
	str[w] = NULL;
	return (str);
}

static char	**st_wordmalloc(char const *s, char c, char **str, size_t w)
{
	size_t	i;
	size_t	p;

	i = 0;
	while (s[i] != '\0')
	{
		p = 0;
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
			{
				p++;
				i++;
			}
			str[w] = (char *)malloc((p + 1) * sizeof(char));
			if (str[w] == NULL)
				return (st_freeall(str, w));
			w++;
		}
		else
			i++;
	}
	return (str);
}

static char	**st_strmalloc(char const *s, char c, size_t w, size_t i)
{
	char	**str;

	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			w++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	str = (char **)malloc((w + 1) * sizeof(char *));
	if (str == NULL)
		return (NULL);
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t	w;
	size_t	p;
	size_t	i;
	char	**str;

	i = 0;
	p = 0;
	w = 0;
	str = st_strmalloc(s, c, w, i);
	str = st_wordmalloc(s, c, str, w);
	str = st_strfill(s, c, str, w);
	return (str);
}
