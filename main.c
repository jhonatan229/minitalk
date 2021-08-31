#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

//int main()
//{
//	kill(4615, SIGUSR1);
//}
int main()
{
	int bit = 0;
	int i = 0;
	char *bite = "ola ola";
	while (i < strlen(bite))
	{
		while (bit < 7)
		{
			if ((bite[i] >> bit) & 1)
			{
				kill(10806,SIGUSR1);
				printf("casa: %i\n", bit);
			}
			else
				kill(10806,SIGUSR2);
			usleep(100);
			bit++;
		}
		bit = 0;
		printf("\n");
		i++;
	}
}