#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static char c;
static size_t count;
static char str[1000];
static int n_str;

void	sig_hanusr(int sig, siginfo_t *info, void *context)
{
	if (sig == 10)
		c += 1 << count;
	count++;
	//printf("sig: %i, signal: %i\n", sig, (sig & 1) << count);
	if (count == 7)
	{
		str[n_str] = c;
		n_str++;
		//write(1, &c, 1);
		if (c == 0)
		{
			str[n_str] = '\n';
			write(1, &str, n_str + 1);
			printf("n = %i\n", n_str);
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
	while(1)
	{
		sigaction(SIGUSR1, &sig, NULL);
		sigaction(SIGUSR2, &sig, NULL);
		pause();
	}
	printf("lasanha\n");
}