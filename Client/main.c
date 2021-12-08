#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

int	send_char(int pid, unsigned char c)
{
	unsigned char	bit;

	bit = 0b10000000;
	while (bit)
	{
		if (bit & c)
		{
			if (kill(pid, SIGUSR1) == -1)
				return (-1);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				return (-1);
		}
		bit >>= 1;
		usleep(70);
	}
	return (0);
}

int	main(int len, char **args)
{
	int		pid;
	char	*input;

	if (len != 3)
		return (-1);
	pid = ft_atoi(args[1]);
	input = args[2];
	while (*input)
	{
		if (send_char(pid, *input) == -1)
			return (-1);
		input++;
	}
	return (0);
}
