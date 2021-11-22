#include <stdlib.h>
#include "../libft.h"

/**
 * Prints string to standard output
 * @param s
 * @return
 */
int	print_string(char *s)
{
	if (!s)
		return (ft_putstr_fd("(null)", 1));
	return (ft_putstr_fd(s, 1));
}

int	print_char(int c)
{
	return (ft_putchar_fd((char)c, 1));
}

int	print_long(long i)
{
	return (ft_putnbr_fd(i, 1));
}

int	print_str_free(char *s)
{
	int	len;

	if (!s)
		return (-1);
	len = print_string(s);
	free(s);
	return (len);
}
