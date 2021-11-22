#include "libft.h"

/**
 * Sets an area of memory to the specified value
 *
 * @param	b	Array of bytes to modify
 * @param	c	Value to set each byte to
 * @param	len	Amount of bytes to set to the specified value
 *
 * @return	The initial value of the pointer to b
 */
char	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp;

	tmp = b;
	while (len > 0)
	{
		len--;
		*tmp = c;
		tmp++;
	}
	return (b);
}
