/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoska <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 11:07:25 by tmoska            #+#    #+#             */
/*   Updated: 2016/11/23 11:18:37 by tmoska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	print_usage(void)
{
	ft_putstr("Usage: ./fillit target_file\n");
	exit(0);
}

int			main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
		print_usage();
	printf("OK\n");
	return (0);
}
