/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirus <kirus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 23:08:11 by kirus             #+#    #+#             */
/*   Updated: 2021/10/17 23:20:39 by kirus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	st_strlen(const char *arr)
{
	size_t	c;

	c = 0;
	while (arr[c] != '\0')
		c++;
	return (c);
}

static int	st_bos(char *s10, char *set0)
{
	size_t	bos;
	size_t	eos;
	size_t	i;

	i = 0;
	bos = 0;
	eos = st_strlen(s10) - 1;
	while (bos < eos)
	{
		while ((s10[bos] != set0[i]) && set0[i] != '\0')
			i++;
		if (i == st_strlen(set0))
			break ;
		bos++;
		i = 0;
	}
	return (bos);
}

static	int	st_eos(char *s10, char *set0, size_t bos)
{
	size_t	eos;
	size_t	i;

	i = 0;
	eos = st_strlen(s10) - 1;
	while (eos >= bos)
	{
		while ((s10[eos] != set0[i]) && set0[i] != '\0')
			i++;
		if (i == st_strlen(set0))
			break ;
		eos--;
		i = 0;
	}
	return (eos);
}

char	*st_mallcpy(size_t eos, size_t bos, const char *s1)
{
	size_t	i;
	char	*s10;

	s10 = (char *)malloc(eos - bos + 1);
	if (s10 == NULL)
		return (NULL);
	i = 0;
	while (bos <= eos)
	{
		s10[i] = s1[bos];
		i++;
		bos++;
	}
	s10[i] = '\0';
	return (s10);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	bos;
	size_t	eos;
	char	*s10;
	char	*set0;

	s10 = (char *)s1;
	set0 = (char *)set;
	if (st_strlen(s10) == 0)
		return (s10);
	if (st_strlen(s10) == 1 && (*s10 == *set0))
	{
		s10 = "";
		return (s10);
	}
	bos = st_bos(s10, set0);
	eos = st_eos(s10, set0, bos);
	if (eos - bos < 0)
	{
		s10 = "";
		return (s10);
	}
	s10 = st_mallcpy(eos, bos, s1);
	return (s10);
}
