/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirus <kirus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:34:18 by kirus             #+#    #+#             */
/*   Updated: 2021/10/19 22:35:24 by kirus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	st_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		add;
	char	num;

	add = 0;
	num = '0';
	if (n == -2147483648)
	{
		st_putchar_fd('-', fd);
		st_putchar_fd('2', fd);
		n = 147483648;
	}
	else if (n < 0)
	{
		st_putchar_fd('-', fd);
		n = -n;
	}
	if (n / 10 != 0)
		ft_putnbr_fd(n / 10, fd);
	add = n % 10;
	num += add;
	write(fd, &num, 1);
}
