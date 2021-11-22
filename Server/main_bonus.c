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

int	func1(void)
{
	g_data.buffer[g_data.pos] = g_data.c;
	g_data.pos++;
	if (!g_data.c)
		return (1);
	if (g_data.len == g_data.pos)
	{
		write(1, g_data.buffer, g_data.len);
		g_data.pos = 0;
		g_data.len = 0;
	}
	g_data.i = 0;
	g_data.c = 0;
	kill(g_data.last_pid, SIGUSR1);
	return (0);
}

void	funcloop(void)
{
	unsigned char	tmp;

	while (1)
	{
		pause();
		usleep(10);
		if (g_data.i != 8)
		{
			kill(g_data.last_pid, SIGUSR1);
			continue ;
		}
		if (g_data.len == 0)
		{
			tmp = g_data.c;
			while (tmp >= 128)
			{
				g_data.len++;
				tmp <<= 1;
			}
			if (g_data.len == 0)
				g_data.len = 1;
		}
		if (func1() == 1)
			break ;
	}
}

int	main(void)
{
	struct sigaction	sa_on;
	struct sigaction	sa_off;

	ft_printf("pid: %i\n", getpid());
	sa_on.sa_flags = SA_SIGINFO;
	sa_on.sa_sigaction = on;
	sigaction(SIGUSR1, &sa_on, NULL);
	sa_off.sa_flags = SA_SIGINFO;
	sa_off.sa_sigaction = off;
	sigaction(SIGUSR2, &sa_off, NULL);
	g_data.len = 0;
	funcloop();
	return (0);
}
