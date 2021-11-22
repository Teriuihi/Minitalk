#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
size_t	ft_strlen(const char *c);
char	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_fd(long n, int fd);
char	*ft_itoa(long n);
#endif
