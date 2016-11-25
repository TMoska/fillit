/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoska <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:16:24 by tmoska            #+#    #+#             */
/*   Updated: 2016/11/25 16:02:45 by tmoska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		al_tetri(char **map, const t_point tetri[4], int indx, t_point sp)
{
	int		i;

	i = -1;
	while (++i < 4)
		map[sp.x + tetri[i].x][sp.y + tetri[i].y] = 65 + indx;
}

void		del_tetri(char **map, const t_point tetri[4], t_point sp)
{
	int	i;

	i = -1;
	while (++i < 4)
		map[sp.x + tetri[i].x][sp.y + tetri[i].y] = '.';
}

char		**create_map(int m_s)
{
	char	**map;
	int		a;
	int		b;

	a = 0;
	b = 0;
	map = (char**)malloc(sizeof(*map) * m_s + 1);
	map[m_s] = NULL;
	while (a < m_s)
	{
		map[a] = (char*)malloc(sizeof(char) * m_s + 1);
		map[a][m_s] = '\0';
		while (b < m_s)
		{
			map[a][b] = '.';
			b++;
		}
		b = 0;
		a++;
	}
	return (map);
}
