/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   data.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 18:02:45 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 18:02:45 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

typedef struct s_data
{
	unsigned char	c;
	int				i;
	int				len;
	int				pos;
	unsigned char	buffer[4];
	int				last_pid;
	int				done;
}	t_data;
#endif
