// header

#include "fillit.h"

void	error_checking(char *buffer)
{
	int	size;

	size = ft_strlen(buffer);
	(void)size;
	// printf("%d\n", (size % (TETRIMINO_SIZE + 1)) - TETRIMINO_SIZE);
	if ((size % (TETRIMINO_SIZE + 1))- TETRIMINO_SIZE)
		exit_error();
}