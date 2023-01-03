/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:24:42 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/03 14:24:52 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_2_elements_a(t_pushSwap piles)
{
	int			i;
	t_inPile	p;

	p.smallest = find_smallest(piles, piles.a);
	p.biggest = find_biggest(piles, piles.a);
	i = piles.size - 2;
	if ((piles.a)[i] > (piles.a)[i + 1])
		swap_a(piles);
}

void	algo_2_elements_b(t_pushSwap piles)
{
	int			i;
	t_inPile	p;

	p.smallest = find_smallest(piles, piles.b);
	p.biggest = find_biggest(piles, piles.b);
	i = piles.size - 2;
	if ((piles.b)[i] > (piles.b)[i + 1])
		swap_b(piles);
}