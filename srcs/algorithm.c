/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:57:40 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/12 20:15:12 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	find_closest_of_the_10(t_pushSwap piles, t_elem *pile, long max)
{
	t_elem	empty;

	int	i;

	i = 0;
	while ((pile + i)->index == EMPTY && i < piles.size)
		i++;
	while (i < piles.size)
	{
		if ((pile + i)->index <= max)
			return (pile[i]);
		else if ((pile + piles.size - 1 - i)->index < max)
			return (pile[piles.size - 1 - i]);
		i++;
	}
	empty.nbr = EMPTY;
	empty.index = EMPTY;
	return (empty);
}

void	algorithm(t_pushSwap piles)
{
	t_inPile	a;
	t_inPile	b;
	t_elem		current;
	long		max;

	max = 9;
	while (pile_size(piles, piles.a) > 0)
	{
		while (pile_size(piles, piles.a) > 0)
		{
			current = find_closest_of_the_10(piles, piles.a, max);
			if (current.index == EMPTY || current.nbr == EMPTY)
				break ;
			place_element_on_top_a(piles, current);
			push_b(piles);
		}
		max += 10;
		push_b(piles);
	}
	while (pile_size(piles, piles.b) > 0)
	{
		current = find_biggest(piles, piles.b);
		if (current.index == EMPTY || current.nbr == EMPTY)
			break ;
		place_element_on_top_b(piles, current);
		push_a(piles);
	}
}