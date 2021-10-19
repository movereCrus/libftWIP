/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirus <kirus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:36:12 by kirus             #+#    #+#             */
/*   Updated: 2021/10/19 15:12:25 by kirus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	**st_freeall(char **str, unsigned int w)
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

static char	**st_strcpy(char const *s, char c, char **str, unsigned int w)
{
	unsigned int	i;
	unsigned int	p;

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

static char	**st_wordmalloc(char const *s, char c, char **str, unsigned int w)
{
	unsigned int	i;
	unsigned int	p;

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
			{
				str = st_freeall(str, w);
				return (str);
			}
			w++;
		}
		i++;
	}
	return (str);
}

static char	**st_strmalloc(char const *s, char c)
{
	unsigned int	i;
	unsigned int	w;
	char			**str;

	i = 0;
	w = 0;
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
	str = (char **)malloc(w * sizeof(char *));
	if (str == NULL)
		return (NULL);
	return (str);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	w;
	unsigned int	p;
	unsigned int	i;
	char			**str;

	i = 0;
	p = 0;
	w = 0;
	str = st_strmalloc(s, c);
	str = st_wordmalloc(s, c, str, w);
	str = st_strcpy(s, c, str, w);
	return (str);
}
