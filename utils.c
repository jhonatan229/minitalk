/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 18:41:32 by jestevam          #+#    #+#             */
/*   Updated: 2021/09/01 18:44:49 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t    ft_strlen(char *s)
{
    size_t    len;

    len = 0;
    if (!s)
        return (0);
    while (s[len])
        len++;
    return (len);
}

static int 	ft_addnum(int *num, char c)
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
