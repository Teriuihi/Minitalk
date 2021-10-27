#include "../headers/libft.h"

/**
 * Checks if a character is a whitespace
 *
 * @param	c	Character to check
 *
 * @return	1 if the character is whitespace, 0 if it's not
 */
static int	ft_isspace(char c)
{
	return (c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r'
		|| c == ' ');
}

/**
 * Converts a string that starts with a digit to an int
 *
 * @param 	str	Char array to convert
 *
 * @return 		Converted integer
 */
static int	convert(const char *str)
{
	int	res;

	if (!ft_isdigit(*str))
		return (0);
	res = (*str - '0') * -1;
	str++;
	while (ft_isdigit(*str))
	{
		res *= 10;
		res -= (*str - '0');
		str++;
	}
	return (res);
}

/**
 * Converts a string to an int
 *
 * @param	str	String to convert
 *
 * @return	The converted integer or 0 on failure
 * 	(keep in mind 0 could be the converted integer)
 */
int	ft_atoi(const char *str)
{
	int	negative;

	negative = -1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			negative = 1;
		str++;
	}
	return (convert(str) * negative);
}
