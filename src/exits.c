/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoska <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 19:33:08 by tmoska            #+#    #+#             */
/*   Updated: 2016/11/23 21:27:32 by tmoska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_usage(void)
{
	ft_putstr("Usage: ./fillit target_file\n");
	exit(0);
}

void	exit_error(void)
{
	ft_putstr("error\n");
	exit(1);
}
