/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoska <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 11:07:25 by tmoska            #+#    #+#             */
/*   Updated: 2016/11/24 00:48:58 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

const t_pattern		g_patterns[19] = {
	{ "###...#.........", 3, 3, 2, {{{0, 0}, {0, 1}, {0, 2}, {1, 2}}}},
	{ ".#...#..##......", 3, 2, 3, {{{0, 1}, {1, 1}, {2, 1}, {2, 0}}}},	// <<<<
	{ "#...###.........", 3, 3, 2, {{{0, 0}, {1, 0}, {1, 1}, {1, 2}}}},
	{ "##..#...#.......", 3, 2, 3, {{{0, 0}, {0, 1}, {1, 0}, {2, 0}}}},
	{ "###.#...........", 3, 3, 2, {{{0, 0}, {0, 1}, {0, 2}, {1, 0}}}},
	{ "##...#...#......", 3, 2, 3, {{{0, 0}, {0, 1}, {1, 1}, {2, 1}}}},
	{ "..#.###.........", 3, 3, 2, {{{0, 2}, {1, 0}, {1, 1}, {1, 2}}}},
	{ "#...#...##......", 3, 2, 3, {{{0, 0}, {1, 0}, {2, 0}, {2, 1}}}},	// <<<
	{ "###..#..........", 3, 3, 2, {{{0, 0}, {0, 1}, {0, 2}, {1, 1}}}},
	{ ".#..##...#......", 3, 2, 3, {{{0, 1}, {1, 0}, {1, 1}, {2, 1}}}},
	{ ".#..###.........", 3, 3, 2, {{{0, 1}, {1, 0}, {1, 1}, {1, 2}}}},
	{ "#...##..#.......", 3, 2, 3, {{{0, 0}, {1, 0}, {1, 1}, {2, 0}}}},
	{ ".##.##..........", 3, 3, 2, {{{0, 1}, {0, 2}, {1, 0}, {1, 1}}}},	// <<<
	{ "#...##...#......", 3, 2, 3, {{{0, 0}, {1, 0}, {1, 1}, {2, 1}}}},
	{ "##...##.........", 3, 3, 2, {{{0, 0}, {0, 1}, {1, 1}, {1, 2}}}},
	{ ".#..##..#.......", 3, 2, 3, {{{0, 1}, {1, 0}, {1, 1}, {2, 0}}}},
	{ "####............", 4, 4, 1, {{{0, 0}, {0, 1}, {0, 2}, {0, 3}}}},
	{ "#...#...#...#...", 4, 1, 4, {{{0, 0}, {1, 0}, {2, 0}, {3, 0}}}},
	{ "##..##..........", 2, 2, 2, {{{0, 0}, {0, 1}, {1, 0}, {1, 1}}}}
};

// ###.	.#..	#...	##..	###.	##..	..#.
// ..#.	.#..	###.	#...	#...	.#..	###.
// ....	##..	....	#...	....	.#..	....
// ....	....	....	....	....	....	....

// #...	###.	.#..	.#..	#...	.##.	#...
// #...	.#..	##..	###.	##..	##..	##..
// ##..	....	.#..	....	#...	....	.#..
// ....	....	....	....	....	....	....

// ##..	.#..	####	#...	##..
// .##.	##..	....	#...	##..
// ....	#...	....	#...	....
// ....	....	....	#...	....

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
	
	i = -1;
	nb_tetriminos = (chars + 1) / (TETRIMINO_SIZE + 1);
	tetriminos = (char**)malloc(sizeof(tetriminos) * nb_tetriminos + 1);
	tetriminos[nb_tetriminos] = NULL;
	while (++i < nb_tetriminos)
	{
		tetriminos[i] = (char*)malloc((sizeof(char) * TETRIMINO_SIZE + 1));
		ft_bzero(tetriminos[i], TETRIMINO_SIZE);
		ft_memcpy(tetriminos[i], buffer, TETRIMINO_SIZE - 1);
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
	int	tetriminos[3] = {1, 7, 12};

	(void)parse_map;
	if (argc != 2)
		print_usage();
	if((fd = open(argv[1], O_RDONLY)) == -1)
		exit_error();
	solve(tetriminos, 3);
	ft_putstr("OK\n");
	return (0);
}
