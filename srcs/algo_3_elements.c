/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:18:31 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/03 14:26:45 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_3_elements_a(t_pushSwap piles)
{
	int			i;
	t_inPile	p;

	p.smallest = find_smallest(piles, piles.a);
	p.biggest = find_biggest(piles, piles.a);
	i = piles.size - 3;
	if ((piles.a)[i] == p.smallest && (piles.a)[i + 1] != p.biggest)
		return ;
	else if (((piles.a)[i] == p.smallest && (piles.a)[i + 1] == p.biggest) \
	|| ((piles.a)[i + 1] == p.smallest && (piles.a)[i + 2] == p.biggest))
		swap_a(piles);
	else if ((piles.a)[i + 1] == p.biggest && (piles.a)[i + 2] == p.smallest)
		rev_rotate_a(piles);
	else
		rotate_a(piles);
	algo_3_elements_a(piles);
}

void	algo_3_elements_b(t_pushSwap piles)
{
	int			i;
	t_inPile	p;

	p.smallest = find_smallest(piles, piles.b);
	p.biggest = find_biggest(piles, piles.b);
	i = piles.size - 3;
	if ((piles.b)[i] == p.smallest && (piles.b)[i + 1] != p.biggest)
		return ;
	else if (((piles.b)[i] == p.smallest && (piles.b)[i + 1] == p.biggest) \
	|| ((piles.b)[i + 1] == p.smallest && (piles.b)[i + 2] == p.biggest))
		swap_b(piles);
	else if ((piles.b)[i + 1] == p.biggest && (piles.b)[i + 2] == p.smallest)
		rev_rotate_b(piles);
	else
		rotate_b(piles);
	algo_3_elements_b(piles);
}
