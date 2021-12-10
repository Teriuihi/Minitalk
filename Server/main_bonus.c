/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_bonus.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 18:02:18 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 18:02:18 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "headers/data.h"
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
	g_data.done = 1;
}

void	off(int norm_is_not, siginfo_t *info, void *always_ideal)
{
	norm_is_not = 0;
	always_ideal = NULL;
	g_data.i++;
	g_data.last_pid = info->si_pid;
	g_data.done = 1;
}

void	loop(void)
{
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
		while (!g_data.done)
			usleep(1);
		usleep(20);
		g_data.done = 0;
		kill(g_data.last_pid, SIGUSR1);
	}
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
	loop();
	return (0);
}
