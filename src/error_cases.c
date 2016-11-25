// header

#include "fillit.h"

void	error_checking(char *buffer)
{
	int	size;
	int	i;
	int	c;
	int	nl_c;

	size = ft_strlen(buffer);
	(void)size;
	// printf("%d\n", (size % (TETRIMINO_SIZE + 1)) - TETRIMINO_SIZE);
	if ((size % (TETRIMINO_SIZE + 1))- TETRIMINO_SIZE)
		exit_error();
	i = -1;
	c = 0;
	nl_c = 0;
	while (++i < size)
	{
		if (nl_c == 4 && buffer[i] == '\n')
			nl_c = 0;
		else if (nl_c == 4 && buffer[c] != '\n')
			exit_error();
		else if (c == 4 && buffer[i] == '\n')
		{
			nl_c++;
			c = 0;
		}
		else if (c == 4 && buffer[i] != '\n')
			exit_error();
		else if (buffer[i] == '.' || buffer[i] == '#')
			c++;
		else
			exit_error();
	}
}