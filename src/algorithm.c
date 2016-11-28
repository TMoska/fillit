/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoska <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:10:49 by tmoska            #+#    #+#             */
/*   Updated: 2016/11/25 16:43:51 by tmoska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	map_start_size(int *tet, int nb_tetriminos)
{
	int		i;
	int		map_size;

	i = 0;
	map_size = g_pattrn[tet[0]].min_map_size;
	while (++i < nb_tetriminos)
		if (g_pattrn[tet[i]].min_map_size > map_size)
			map_size = g_pattrn[tet[i]].min_map_size;
	while (nb_tetriminos * 4 > map_size * map_size)
		map_size++;
	return (map_size);
}

static int	point_ok(char **map, const t_point tet[4], int a, int b)
{
	int		c;
	int		fits;

	c = -1;
	fits = 0;
	while (++c < 4)
		if (!ft_strncmp(".", &map[tet[c].x + a][tet[c].y + b], 1))
			fits++;
	return (fits == 4);
}

static int	recs(char **map, int *tet, t_map_info mi, int c_tet)
{
	t_point	sp;
	int		a;
	int		b;

	a = -1;
	while (++a <= (mi.m_s - g_pattrn[tet[c_tet]].height))
	{
		b = -1;
		while (++b <= (mi.m_s - g_pattrn[tet[c_tet]].width))
		{
			if (point_ok(map, g_pattrn[tet[c_tet]].cord.pts, a, b))
			{
				sp.x = a;
				sp.y = b;
				al_tetri(map, g_pattrn[tet[c_tet]].cord.pts, c_tet, sp);
				if (c_tet == mi.n_tet - 1 || recs(map, tet, mi, c_tet + 1))
					return (1);
				else
					del_tetri(map, g_pattrn[tet[c_tet]].cord.pts, sp);
			}
		}
	}
	return (0);
}

static char	**rec_solver(int *tet, int map_size, int nb_tetriminos)
{
	char		**map;
	t_map_info	mi;

	mi.m_s = map_size;
	mi.n_tet = nb_tetriminos;
	map = create_map(map_size);
	if (!recs(map, tet, mi, 0))
		return (rec_solver(tet, map_size + 1, nb_tetriminos));
	else
	{
		print_map(map, map_size);
		exit(0);
	}
}

void		solve(int *tet, int nb_tetriminos)
{
	int		map_size;

	map_size = map_start_size(tet, nb_tetriminos);
	rec_solver(tet, map_size, nb_tetriminos);
}
