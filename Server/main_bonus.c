#include <unistd.h>
#include <signal.h>
#include "headers/rename.h"
#include "libft/ft_printf/ft_printf.h"

t_data	g_data;

void	on(int norm_is_not, siginfo_t *info, void *always_ideal)
{
	unsigned char	bit;

	norm_is_not = 0;
	always_ideal = NULL;
	bit = 0b10000000;
	g_data.c |= bit >> g_data.i;
	g_data.i++;
	g_data.last_pid = info->si_pid;
}

void	off(int norm_is_not, siginfo_t *info, void *always_ideal)
{
	norm_is_not = 0;
	always_ideal = NULL;
	g_data.i++;
	g_data.last_pid = info->si_pid;
}

int	main(void)
{
	int					pid;
	struct sigaction	sa_on;
	struct sigaction	sa_off;

	pid = getpid();
	ft_printf("pid: %i\n", pid);
	sa_on.sa_flags = SA_SIGINFO;
	sa_on.sa_sigaction = on;
	sigaction(SIGUSR1, &sa_on, NULL);
	sa_off.sa_flags = SA_SIGINFO;
	sa_off.sa_sigaction = off;
	sigaction(SIGUSR2, &sa_off, NULL);
	while (1)
	{
		pause();
		if (g_data.i == 8)
		{
			write(1, &(g_data.c), 1);
			if (g_data.c == 0)
				break ;
			g_data.i = 0;
			g_data.c = 0;
		}
		usleep(20);
		kill(g_data.last_pid, SIGUSR1);
	}
	return (0);
}
