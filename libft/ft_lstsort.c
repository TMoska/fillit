/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoska <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 21:42:33 by tmoska            #+#    #+#             */
/*   Updated: 2016/11/18 21:44:43 by tmoska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		swap_nodes(t_list **current)
{
	t_list *tmp;

	tmp = (*current);
	(*current) = (*current)->next;
	tmp->next = (*current)->next;
	(*current)->next = tmp;
}

void			ft_lstsort(t_list **begin_list, int (*cmp)())
{
	t_list	*tmp;
	int		sorted;

	if (!(*begin_list))
		return ;
	sorted = 0;
	while (!sorted)
	{
		tmp = *begin_list;
		sorted = 1;
		if ((*cmp)(tmp->content, tmp->next->content) > 0)
		{
			swap_nodes(begin_list);
			sorted = 0;
		}
		while (tmp->next->next)
		{
			if ((*cmp)(tmp->next->content, tmp->next->next->content) > 0)
			{
				sorted = 0;
				swap_nodes(&(tmp->next));
			}
			tmp = tmp->next;
		}
	}
}
