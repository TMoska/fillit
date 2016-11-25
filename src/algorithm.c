// tetriminos = [1, 7, 12];

#include "fillit.h"

int		map_start_size(int *tetriminos, int nb_tetriminos)
{
	int	i;
	int	map_size;

	i = 0;
	map_size = g_patterns[tetriminos[0]].min_map_size;
	while (++i < nb_tetriminos)
		if (g_patterns[tetriminos[i]].min_map_size > map_size)
			map_size = g_patterns[tetriminos[i]].min_map_size;
	while (nb_tetriminos * 4 > map_size * map_size)
		map_size++;
	return (map_size);
}

char	**create_map(int map_size)
{
	char	**map;
	int		a;
	int		b;

	a = 0;

	b = 0;
	map = (char**)malloc(sizeof(*map) * map_size + 1);
	map[map_size] = NULL;
	while (a < map_size)
	{
		map[a] = (char*)malloc(sizeof(char) * map_size + 1);
		map[a][map_size] = '\0';
		while (b < map_size)
		{
			map[a][b] = '.';
			b++;
		}
		b = 0;
		a++;
	}
	return (map);
}

int		point_can_be_used(char **map, const t_point tetri[4], int a, int b)
{
	int c;
	int fits;

	// printf("checking (%i, %i)\n", a, b);
	c = -1;
	fits = 0;
	while (++c < 4)
		if (!ft_strncmp(".", &map[tetri[c].x + a][tetri[c].y + b], 1))
			fits++;		
	if (fits == 4)
		return (1);
	else
		return (0);
}

void	allocate_tetri(char **map, const t_point tetri[4], int tetri_index, t_point solution_point	)
{
	int	i;

	// printf("Allocating block #%i\n", tetri_index);
	i = -1;
	while (++i < 4)
		map[solution_point.x + tetri[i].x][solution_point.y + tetri[i].y] = 65 + tetri_index;
}

void	delete_tetri(char **map, const t_point tetri[4], int tetri_index, t_point solution_point	)
{
	int	i;

	// printf("Deleting block #%i\n", tetri_index);
	(void)tetri_index;
	i = -1;
	while (++i < 4)
		map[solution_point.x + tetri[i].x][solution_point.y + tetri[i].y] = '.';
}

int			rec_map(char **map, int *tetriminos, int map_size, int tetri_count, int nb_tetriminos)
{
	t_point sp;
	int	a;
	int	b;

	// printf("tetri: %i\nmap_size: %i\n", tetri_count, map_size);
	a = -1;
	while (++a <= (map_size - g_patterns[tetriminos[tetri_count]].height))
	{
		b = -1;
		while (++b <= (map_size - g_patterns[tetriminos[tetri_count]].width))
		{
			// printf("AT POINT (%i, %i) with #%i\n", a, b, tetri_count);
			if (point_can_be_used(map, g_patterns[tetriminos[tetri_count]].coordinates.points, a, b))
			{
				// printf("GOOD\n");
				sp.x = a;
				sp.y = b;
				allocate_tetri(map, g_patterns[tetriminos[tetri_count]].coordinates.points, tetri_count, sp);
				if (tetri_count == nb_tetriminos - 1) // Number of tetriminos - 1		T.M.
				{
					// printf("TETRI COUNT 2\n");
					return (1);
					// print_map(map, map_size);
				}
				else
				{
					// printf("next one\n");
					// exit(0);
					if(rec_map(map, tetriminos, map_size, tetri_count + 1, nb_tetriminos))
						return (1);
					else
					{
						delete_tetri(map, g_patterns[tetriminos[tetri_count]].coordinates.points, tetri_count, sp);
					}
				}
			}
		}
	}
	// printf("done, returning\n");
	return (0);
}

char		**rec_solver(int *tetriminos, int map_size, int nb_tetriminos)
{
	char **map;

	map = create_map(map_size);
	if (!rec_map(map, tetriminos, map_size, 0, nb_tetriminos))
		return (rec_solver(tetriminos, map_size + 1, nb_tetriminos));
	else
	{
		print_map(map, map_size);
		exit (0);
	}
}

void		solve(int *tetriminos, int nb_tetriminos)
{
	int	map_size;

	// printf("\n");
	map_size = map_start_size(tetriminos, nb_tetriminos);
	rec_solver(tetriminos, map_size, nb_tetriminos);
}
	