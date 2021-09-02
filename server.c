/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 18:42:51 by jestevam          #+#    #+#             */
/*   Updated: 2021/09/02 00:34:08 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char *store_char(char *str, char c)
{
	char *tmp;
	int i;

	tmp = malloc(ft_strlen(str) + 2);
	if (tmp == NULL)
	{
		free(str);
		return (NULL);
	}
	i = -1;
	if (!str)
	{
		tmp[++i] = c;
		tmp[i + 1] = 0;
	}
	else
	{
		while (str[++i])
			tmp[i] = str[i];
		tmp[i] = c;
		tmp[i + 1] = 0;
		free(str);
	}
	return (tmp);
}

void	sig_hanusr(int sig, siginfo_t *info, void *context)
{
	static size_t count;
	static char c;
	static char *msg;

	(void) context;
	if (sig == SIGUSR1)
		c += 1 << count;
	count++;
	//printf("sig: %i, signal: %i\n", sig, (sig & 1) << count);
	if (count == 8)
	{
		//write(1, &c, 1);
		if (c)
			msg = store_char(msg, c);
		else
		{
			write(1, msg, ft_strlen(msg));
			write(1, "\n", 1);
			free(msg);
			msg = NULL;
			kill(info->si_pid, SIGUSR1);
		}
		count = 0;
		c = 0;
	}
}

int main()
{
	struct sigaction	sig;
	
	write(1, "PID: ", 5);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	sig.sa_sigaction = sig_hanusr;
	sig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sig, NULL) == -1)
		return (1);
	if (sigaction(SIGUSR2, &sig, NULL) == -1)
		return (1);
	while(1)
		pause();
}