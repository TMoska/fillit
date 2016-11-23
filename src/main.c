/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoska <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 11:07:25 by tmoska            #+#    #+#             */
/*   Updated: 2016/11/23 21:46:38 by tmoska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	count_chars(int fd, char *buffer)
{
	int	chars;
	
	chars = read(fd, buffer, BUFF_SIZE);
	if ((chars + 1 ) % (TETRIMINO_SIZE + 1))
		exit_error();
	return (chars);
}

static void	init_tetriminos(char *buffer, int chars)
{
	char		**tetriminos;
	int			nb_tetriminos;
	int			i;
	
	(void)buffer;
	i = 0;
	nb_tetriminos = (chars + 1) / (TETRIMINO_SIZE + 1);
	tetriminos = (char**)malloc(sizeof(tetriminos) * nb_tetriminos + 1);
	tetriminos[nb_tetriminos] = NULL;
	while (i < nb_tetriminos)
	{`
		tetriminos[i] = (char*)malloc(sizeof(char) + 1);
		ft_memcpy(tetriminos[i], buffer, TETRIMINO_SIZE);
		printf("%s \n", tetriminos[0]);
		i++;
	}
}

static void	parse_map(int fd)
{
	char	buffer[BUFF_SIZE + 1];
	int		chars;

	buffer[BUFF_SIZE] = '\0';
	chars = count_chars(fd, buffer);
	init_tetriminos(buffer, chars);
}

int			main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		print_usage();
	if((fd = open(argv[1], O_RDONLY)) == -1)
		exit_error();
	parse_map(fd);
	ft_putstr("OK\n");
	return (0);
}
