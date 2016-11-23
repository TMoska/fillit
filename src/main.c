/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoska <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 11:07:25 by tmoska            #+#    #+#             */
/*   Updated: 2016/11/23 18:52:38 by tmoska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	print_usage(void)
{
	ft_putstr("Usage: ./fillit target_file\n");
	exit(0);
}

static void	exit_error(void)
{
	ft_putstr("error\n");
	exit(0);
}

static int	count_chars(int fd, char *buffer)
{
	int	chars;
	
	chars = read(fd, buffer, BUFF_SIZE);
	if ((chars + 1 ) % (TETRIMINO_SIZE + 1))
		exit_error();
	return (chars);
}

static void	parse_map(int fd)
{
	char	buffer[BUFF_SIZE + 1];
	int		chars;

	buffer[BUFF_SIZE] = '\0';
	chars = count_chars(fd, buffer);	
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
