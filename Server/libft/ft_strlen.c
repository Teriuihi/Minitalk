#include "libft.h"

/**
 * Calculates the length of a string
 *
 * @param	c	String to get the length of
 *
 * @return	The length of the string
 */
size_t	ft_strlen(const char *c)
{
	const char	*tmp;

	tmp = c;
	while (*tmp)
		tmp++;
	return (tmp - c);
}
