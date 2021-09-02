/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 18:41:32 by jestevam          #+#    #+#             */
/*   Updated: 2021/09/02 18:34:49 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

static	int	ft_addnum(int *num, char c)
{
	if (c >= '0' && c <= '9')
	{
		if (*num != 0)
			*num *= 10;
		*num += c - '0';
		return (0);
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int	sinal;
	int	num;

	num = 0;
	sinal = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sinal = -1;
		nptr++;
	}
	while (ft_addnum(&num, *nptr) == 0)
		nptr++;
	return (num * sinal);
}

static int	ft_to_positive(int nb, int fd)
{
	write(fd, "-", 1);
	if (nb == -2147483648)
	{
		write(fd, "2", 1);
		nb = -147483648;
	}
	return (nb - nb - nb);
}

void	ft_putnbr_fd(int nb, int fd)
{
	char	number;

	if (nb == 2147483647)
	{
		write(fd, "2", 1);
		nb = 147483647;
	}
	if (nb < 0)
		nb = ft_to_positive(nb, fd);
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
		number = (nb % 10) + '0';
		write(fd, &number, 1);
	}
	else
	{
		number = nb + '0';
		write(fd, &number, 1);
	}
}
