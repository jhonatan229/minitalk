/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 17:05:21 by jestevam          #+#    #+#             */
/*   Updated: 2021/09/02 00:45:34 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void print_resp(int sig)
{
	(void)sig;
	write(1, "SEND MESSAGE!\n", 14);
	exit(1);
}

int send_mssg(int pid,char *mssg, int len_mssg)
{
	int count;
	int	bit;
	
	count = 0;
	bit = 0;
	while (count <= len_mssg)
	{
		while (bit < 8)
		{
			if ((mssg[count] >> bit) & 1)
				kill(pid,SIGUSR1);
			else
				kill(pid,SIGUSR2);
			usleep(200);
			bit++;
		}
		bit = 0;
		count++;
	}
	return (0);
}
int main(int argc, char **argv)
{
	int pid;
	if (argc != 3)
	{
		write(1, "you must give the PID and message that you want send\n", 58);
		return (1);
	}
	signal(SIGUSR1, print_resp);
	pid = ft_atoi(argv[1]);
	send_mssg(pid, argv[2], ft_strlen(argv[2]));
	while (1)
		pause();
	return (0);
}