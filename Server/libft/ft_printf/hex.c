#include "internal.h"

char	*get_hex_lower(long nbr)
{
	return (ft_get_base(nbr, "0123456789abcdef", 0));
}

char	*get_hex_upper(long nbr)
{
	return (ft_get_base(nbr, "0123456789ABCDEF", 0));
}

char	*get_pointer(unsigned long nbr)
{
	return (ft_get_base_ul(nbr, "0123456789abcdef", "0x"));
}
