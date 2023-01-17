/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_top.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:39:08 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/12 20:11:22 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	in_superior_part(t_pushSwap piles, t_elem *pile, t_elem elem)
{
	int	i;
	int	count;

	i = 0;
	while (i < piles.size)
	{
		if ((pile + i)->index != EMPTY)
			break ;
		i++;
	}
	count = 0;
	while (i < piles.size)
	{
		if ((pile + i)->index == elem.index)
		{
			if (count < pile_size(piles, pile) / 2)
				return (1);
			else
				return (0);
		}
		count++;
		i++;
	}
	return (0);
}

void	place_element_on_top_a(t_pushSwap piles, t_elem elem)
{
	int		i;
	t_elem	*pile;

	i = 0;
	while ((piles.a + i)->index == EMPTY)
		i++;
	pile = (piles.a + i);
	if (i >= piles.size)
		return ;
	while ((pile)->index != elem.index)
	{
		if (in_superior_part(piles, piles.a, elem))
			rotate_a(piles);
		else
			rev_rotate_a(piles);
	}
}

void	place_element_on_top_b(t_pushSwap piles, t_elem elem)
{
	int		i;
	t_elem	*pile;

	i = 0;
	while ((piles.b + i)->index == EMPTY)
		i++;
	pile = (piles.b + i);
	if (i >= piles.size)
		return ;
	while ((pile)->index != elem.index)
	{
		if (in_superior_part(piles, piles.b, elem))
			rotate_b(piles);
		else
			rev_rotate_b(piles);
	}
}