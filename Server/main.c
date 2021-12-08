#include <unistd.h>
#include <signal.h>
#include "headers/data.h"
#include "libft/ft_printf/ft_printf.h"

t_data	g_data;

void	on(int ignored)
{
	unsigned char	bit;

	ignored = 0;
	bit = 0b10000000;
	g_data.c |= bit >> g_data.i;
	g_data.i++;
}

void	off(int ignored)
{
	ignored = 0;
	g_data.i++;
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("pid: %i\n", pid);
	signal(SIGUSR1, on);
	signal(SIGUSR2, off);
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
	}
	return (0);
}
