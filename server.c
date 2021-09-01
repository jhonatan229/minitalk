#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char c;
static size_t count;
static char *msg;
static int n_str;

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
	if (sig == 10)
		c += 1 << count;
	count++;
	//printf("sig: %i, signal: %i\n", sig, (sig & 1) << count);
	if (count == 7)
	{
		n_str++;
		//write(1, &c, 1);
		printf("mano\n");
		if (c)
			msg = store_char(msg, c);
		else
		{
			write(1, msg, ft_strlen(msg));
			printf("n = %i\n", n_str);
			free(msg);
			msg = NULL;
			n_str = 0;
			kill(info->si_pid, SIGUSR1);
		}
		count = 0;
		c = 0;
	}
}

int main()
{
	c = 0;
	count = 0;
	n_str = 0;
	printf("pid? %d\n", getpid());
	struct sigaction	sig;
	sig.sa_sigaction = sig_hanusr;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while(1)
		pause();
}