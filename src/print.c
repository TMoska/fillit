#include "libft.h"

void		print_map(char **map, int map_size)
{
	int row;

	row = -1;
	while (++row < map_size)
  {
		ft_putstr(map[row]);
    ft_putchar('\n');
  }
}
