/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoska <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:05:19 by tmoska            #+#    #+#             */
/*   Updated: 2016/11/25 17:06:18 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	check_map(char *buffer, int i, int c, int size)
{
	int	nl_c;

	nl_c = 0;
	while (++i < size)
	{
		if (nl_c == 4 && buffer[i] == '\n')
			nl_c = 0;
		else if (nl_c == 4 && buffer[c] != '\n')
			exit_error();
		else if (c == 4 && buffer[i] == '\n')
		{
			nl_c++;
			c = 0;
		}
		else if (c == 4 && buffer[i] != '\n')
			exit_error();
		else if (buffer[i] == '.' || buffer[i] == '#')
			c++;
		else
			exit_error();
	}
}

void		error_checking(char *buffer)
{
	int	size;
	int	i;
	int	c;

	size = ft_strlen(buffer);
	if ((size % (TETRIMINO_SIZE + 1)) - TETRIMINO_SIZE)
		exit_error();
	i = -1;
	c = 0;
	check_map(buffer, i, c, size);
}
