#include "libft.h"

/**
 * Allocates an array with a specified size and
 * 	set's all bytes in that array to 0
 *
 * @param	count	length of the array
 * @param	size	size of the individual array sections
 *
 * @return	Array of specified length or NULL on failure
 */
void	*ft_calloc(size_t count, size_t size)
{
	void	*loc;

	loc = malloc(size * count);
	if (loc == 0)
		return (NULL);
	ft_memset(loc, 0, size * count);
	return (loc);
}
