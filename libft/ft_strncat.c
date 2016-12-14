/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moska <moska@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 19:36:09 by tmoska            #+#    #+#             */
/*   Updated: 2016/12/14 17:25:40 by moska            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = s1;
	while (*s1)
		s1++;
	while (i < n && *s2)
	{
		*s1 = *s2;
		s1++;
		s2++;
		i++;
	}
	*s1 = '\0';
	return (tmp);
}
