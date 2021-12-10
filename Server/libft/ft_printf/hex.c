/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hex.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 18:02:56 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 18:02:56 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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
