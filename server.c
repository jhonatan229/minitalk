#include <signal.h>
#include <unistd.h>
#include <stdio.h>

static char c;
static size_t count;

void	sig_hanusr(int sig)
{
	if (sig == 10)
		c += 1 << count;
	count++;
	//printf("sig: %i, signal: %i\n", sig, (sig & 1) << count);
	if (count == 7)
	{
		write(1, &c, 1);
		count = 0;
		c = 0;
	}
	//write(STDOUT_FILENO,"mamae queridaz\n", 15);
}

int main()
{
	c = 0;
	count = 0;
	printf("pid? %d\n", getpid());
	while(1)
	{
		signal(SIGUSR1, sig_hanusr);
		signal(SIGUSR2, sig_hanusr);
		pause();
	}
}