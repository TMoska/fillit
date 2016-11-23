# ifndef FILLIT_H
# define FILLIT_H

#include <stdio.h>
#include <stdlib.h>
# include "libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>

# define TETRIMINO_W	(4 + 1)
# define TETRIMINO_H	4
# define MAX_TETRIMINOS	25
# define TETRIMINO_SIZE	TETRIMINO_W * TETRIMINO_H
# define BUFF_SIZE		MAX_TETRIMINOS * (TETRIMINO_SIZE + 1)

typedef struct		s_pattern
{
	char			*pattern;
	int				min_map_size;
}					t_pattern;

void	print_usage(void);
void	exit_error(void);

# endif
