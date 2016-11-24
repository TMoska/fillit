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
# define MAX_TETRIMINOS	26
# define TETRIMINO_SIZE	TETRIMINO_W * TETRIMINO_H
# define BUFF_SIZE		MAX_TETRIMINOS * (TETRIMINO_SIZE + 1) - 1

typedef struct  s_point
{
  int           x;
  int           y;
}               t_point;

typedef struct  s_tetriminos
{
    t_point     points[4];
}               t_tetriminos;


typedef struct	s_pattern
{
	char		*pattern;
    int			min_map_size;
    int         width;
    int         height;
    t_tetriminos    coordinates;
}				t_pattern;

extern const t_pattern g_patterns[19];
void	print_usage(void);
void	exit_error(void);
void	error_checking(char *buffer);
int		check_line(char *line);
int		check_row(char	**map);
void	move_line_up(char **map);
void	move_row_left(char **map);
char	*convert_map(char **map);
int		*tetrimino_blocks(char **map, int nb_tetriminos);
void		solve(int *tetriminos, int nb_tetriminos);
void	print_map(char **map, int map_size);
# endif
