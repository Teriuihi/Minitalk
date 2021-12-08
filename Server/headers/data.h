#ifndef RENAME_H
# define RENAME_H
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
