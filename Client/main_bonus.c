/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_bonus.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 18:02:24 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 18:02:24 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

void	empty1(int ignored)
{
	ignored += 0;
}

void	empty2(int ignored)
{
	ignored += 0;
}

int	send_char(int pid, unsigned char c)
{
	unsigned char	bit;

	bit = 0b10000000;
	while (bit)
	{
		if (bit & c)
		{
			usleep(50);
			if (kill(pid, SIGUSR1) == -1)
				return (-1);
		}
		else
		{
			usleep(50);
			if (kill(pid, SIGUSR2) == -1)
				return (-1);
		}
		pause();
		bit >>= 1;
	}
	return (0);
}

int	main(int len, char **args)
{
	int		pid;
	char	*input;

	signal(SIGUSR1, empty1);
	signal(SIGUSR2, empty2);
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
