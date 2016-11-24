//header

#include "fillit.h"

void	tetrimino_blocks(char **map, int nb_tetriminos)
{
	int		c;
	int		g_count;
	int		blocks[nb_tetriminos];
	char	**map_location;
	char	*g_map;


	c = 0;
	while (c < nb_tetriminos)
	{
		map_location = &(map[c * TETRIMINO_H]);
		while (check_line(*map_location))
		{
			move_line_up(map_location);
		}
		while (check_row(map_location))
		{
			move_row_left(map_location);
		}
		g_map = convert_map(map_location);
		// (void)g_map;
		g_count = 19 - 1;
		while (ft_strcmp(g_patterns[g_count].pattern, g_map))
			g_count--;
		blocks[c] = g_count;
		printf("%d\n", g_count);
		c++;
	}
	(void)*blocks;
	// while (g_map)
	// {
	// 	ft_putstr(g_map++);
	// 	ft_putchar('\n');
	// }
}