#include "libft.h"

/**
 * Writes a number to the specified file descriptor
 * @param	n	The number to write
 * @param	fd	The file descriptor to write to
 *
 * @return	amount of characters written
 */
int	ft_putnbr_fd(long n, int fd)
{
	char	*s;
	int		len;

	s = ft_itoa(n);
	len = ft_strlen(s);
	ft_putstr_fd(s, fd);
	free(s);
	return (len);
}
