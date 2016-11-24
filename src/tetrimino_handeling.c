//header

#include "fillit.h"

static int	check_line(char *line)
{
	int	ret;

	ret = 1;
	while (*line)
	{
		if (*line++ != '.')
			ret = 0;
	}
	return (ret);
}

static int	check_row(char **map)
{
	int	ret;
	int	count;

	count = 4;
	ret = 1;
	while (count--)
	{
		if (map[count][0] != '.')
			ret = 0;
	}
	return (ret);
}

void	tetrimino_blocks(char **map)
{
	int		c;
	char	*tmp;

	c = 0;
	while ()
	{
		if (check_row)
		{
			tmp = map[c];
			map[c] = map[c + 1]
			map[c + 4] //start moving tetrimino to right place
		}
	}
}