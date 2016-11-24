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

	printf("checking (%i, %i)\n", a, b);
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

void	find_next_position(char **map, int map_size, const t_point tetri[4], int pattern_index)
{
	int	a;
	int b;
	t_point solution_point;

	a = -1;
	while (++a <= (map_size - g_patterns[pattern_index].height))
	{
		b = -1;
		while (++b <= (map_size - g_patterns[pattern_index].width))
		{
			if (point_can_be_used(map, tetri, a, b))
			{
				printf("GOOD\n");
				solution_point.x = a;
				solution_point.y = b;
				// allocate_tetri(map, solution_point);
			}
		}
	}
}

// void	allocate_tetri(char **map, const t_point tetri[4], int tetri_index, int start_x, int start_y	)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < 4)
// 		map[tetri[i].x][tetri[i].y] = 65 + tetri_index;
// }

void		solve(int *tetriminos, int nb_tetriminos)
{
	int	map_size;
	int	i;
	char	**map;

	i = 0;
	map_size = map_start_size(tetriminos, nb_tetriminos);
	map = create_map(map_size);
	while (i < 1)
	{
		printf("Allocating block #%i\n", i);
		find_next_position(map, map_size, g_patterns[tetriminos[i]].coordinates.points, pattern_index);
		// allocate_tetri(map, g_patterns[tetriminos[i]].coordinates.points, i, map_size, tetriminos[i]);
		i++;
	}
	print_map(map, map_size);
}
	