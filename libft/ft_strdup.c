/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoska <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 17:00:08 by tmoska            #+#    #+#             */
/*   Updated: 2016/11/17 17:00:43 by tmoska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*str;

	if ((str = (char*)malloc(sizeof(*str) * (ft_strlen(src) + 1))))
		ft_strcpy(str, src);
	else
		return (0);
	return (str);
}
