/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino_handeling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoska <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:03:40 by tmoska            #+#    #+#             */
/*   Updated: 2016/11/25 16:04:29 by tmoska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		push_array(char *map, int *blocks, int c)
{
	int			count;

	count = -1;
	while (++count <= 18)
	{
		if (!(ft_strcmp(g_pattrn[count].pattern, map)))
		{
			blocks[c] = count;
			break ;
		}
		if (count == 18)
			exit_error();
	}
}

static void		legit_tetrimino(char **map)
{
	int		r_c;
	int		c_c;
	int		check_hash;
	int		check_dots;

	r_c = 4;
	c_c = 4;
	check_dots = 12;
	check_hash = 4;
	while (c_c--)
	{
		while (r_c--)
		{
			if (map[c_c][r_c] == '#')
				check_hash--;
			if (map[c_c][r_c] == '.')
				check_dots--;
		}
		r_c = 4;
	}
	if (check_dots || check_hash)
		exit_error();
}

int				*tetrimino_blocks(char **map, int nb_tetriminos)
{
	int			c;
	int			*blocks;
	char		**map_location;
	char		*conv_map;

	c = 0;
	blocks = (int *)ft_memalloc(sizeof(int) * nb_tetriminos);
	while (c < nb_tetriminos)
	{
		map_location = &(map[c * TETRIMINO_H]);
		legit_tetrimino(map_location);
		while (check_line(*map_location))
			move_line_up(map_location);
		while (check_row(map_location))
			move_row_left(map_location);
		conv_map = convert_map(map_location);
		push_array(conv_map, blocks, c);
		c++;
	}
	return (blocks);
}
