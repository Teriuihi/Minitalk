#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "headers/rename.h"

t_data	g_data;

void  on(int sig, siginfo_t *info, void *context)
{
	unsigned char	bit;

	bit = 0b10000000;
	g_data.c |= bit >> g_data.i;
	g_data.i++;
	g_data.last_pid = info->si_pid;
}

void	off(int sig, siginfo_t *info, void *context)
{
	g_data.i++;
	g_data.last_pid = info->si_pid;
}

int	main(void)
{
	int					pid;
	unsigned char		tmp;
	struct	sigaction sa_on;
	struct	sigaction sa_off;

	pid = getpid();
	printf("pid: %i\n", pid); //TODO replace with my own printf
	sa_on.sa_flags = SA_SIGINFO;
	sa_on.sa_sigaction = on;
	sigaction(SIGUSR1, &sa_on, NULL);
	sa_off.sa_flags = SA_SIGINFO;
	sa_off.sa_sigaction = off;
	sigaction(SIGUSR2, &sa_off, NULL);
	g_data.len = 0;
	while (1)
	{
		pause();
		usleep(10);
		if (g_data.i != 8) {
			kill(g_data.last_pid, SIGUSR1);
			continue;
		}
		if (g_data.len == 0)
		{
			tmp = g_data.c;
			while (tmp >= 128)
			{
				g_data.len++;
				tmp <<= 1;
			}
//				printf("%i\n", g_data.len);
			if (g_data.len == 0)
				g_data.len = 1;
		}
		g_data.buffer[g_data.pos] = g_data.c;
		g_data.pos++;
		if (!g_data.c)
			break ;
//			printf("%i - %i\n", g_data.len, g_data.pos);
		if (g_data.len == g_data.pos)
		{
			write(1, g_data.buffer, g_data.len);
			g_data.pos = 0;
			g_data.len = 0;
		}
		g_data.i = 0;
		g_data.c = 0;
		kill(g_data.last_pid, SIGUSR1);
	}
	return (0);
}