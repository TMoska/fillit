/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handeling_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoska <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:11:05 by tmoska            #+#    #+#             */
/*   Updated: 2016/11/25 16:12:12 by tmoska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check_line(char *line)
{
	int		ret;

	ret = 1;
	while (*line)
	{
		if (*line++ != '.')
			ret = 0;
	}
	return (ret);
}

int			check_row(char **map)
{
	int		ret;
	int		count;

	count = 4;
	ret = 1;
	while (count--)
	{
		if (map[count][0] != '.')
			ret = 0;
	}
	return (ret);
}

void		move_line_up(char **map)
{
	char	*tmp;
	int		line_pos;

	tmp = map[0];
	line_pos = 0;
	while (line_pos < 3)
	{
		map[line_pos] = map[line_pos + 1];
		line_pos++;
	}
	map[line_pos] = tmp;
}

void		move_row_left(char **map)
{
	int		row_pos;
	int		line_pos;

	row_pos = 0;
	line_pos = 0;
	while (row_pos < 3)
	{
		while (line_pos <= 3)
		{
			map[line_pos][row_pos] = map[line_pos][row_pos + 1];
			line_pos++;
		}
		row_pos++;
		line_pos = 0;
	}
	while (line_pos <= 3)
		map[line_pos++][row_pos] = '.';
}

char		*convert_map(char **map)
{
	char	*g_map;
	int		pos;

	g_map = ft_memalloc(17);
	ft_bzero(g_map, 17);
	pos = 0;
	while (pos <= 3)
	{
		ft_strcpy(&g_map[pos * TETRIMINO_H], (const char *)map[pos]);
		pos++;
	}
	return (g_map);
}
