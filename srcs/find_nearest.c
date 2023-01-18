/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_nearest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:53:46 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/18 18:13:54 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	skip_empty(t_pushSwap piles, t_elem *pile)
{
	int		i;

	i = 0;
	while (i < piles.size && (pile + i)->index == EMPTY)
		i++;
	return (i);
}

static t_elem	find_nearest_bis(t_pushSwap piles, \
	t_elem *pile, t_numbers numbers, t_ij ij)
{
	t_elem	not_found;

	not_found.index = EMPTY;
	not_found.nbr = EMPTY;
	if ((pile + ij.i)->index != EMPTY
		&& (pile + ij.i)->index == (numbers.smallest).index)
		return (numbers.smallest);
	else if ((pile + ij.j)->index != EMPTY
		&& (pile + ij.j)->index == (numbers.smallest).index)
		return (numbers.smallest);
	else if (ij.i + 1 < piles.size && (pile + ij.i + 1)->index != EMPTY
		&& (pile + ij.i + 1)->index == (numbers.smallest).index)
		return (numbers.smallest);
	else if (ij.j - 1 >= 0 && (pile + ij.j - 1)->index != EMPTY
		&& (pile + ij.j - 1)->index == (numbers.smallest).index)
		return (numbers.smallest);
	else if ((pile + ij.i)->index != EMPTY
		&& (pile + ij.i)->index == (numbers.sec_smallest).index)
		return (numbers.sec_smallest);
	else if ((pile + ij.j)->index != EMPTY
		&& (pile + ij.j)->index == (numbers.sec_smallest).index)
		return (numbers.sec_smallest);
	return (not_found);
}

t_elem	find_nearest(t_pushSwap piles, t_elem *pile, t_numbers numbers)
{
	t_ij	ij;
	t_elem	not_found;
	t_elem	current;

	ij.i = skip_empty(piles, pile);
	ij.j = piles.size - 1;
	while (ij.i < piles.size)
	{
		current = find_nearest_bis(piles, pile, numbers, ij);
		if (current.index != EMPTY)
			return (current);
		(ij.i)++;
		(ij.j)--;
	}
	not_found.index = EMPTY;
	not_found.nbr = EMPTY;
	return (not_found);
}

t_elem	find_closest_one(t_pushSwap piles, t_elem *pile, long a, long b)
{
	int		i;
	int		j;
	t_elem	not_found;

	i = skip_empty(piles, pile);
	j = piles.size - 1;
	while (i < piles.size)
	{
		if ((pile + i)->index != EMPTY && ((pile + i)->index == a
				|| (pile + i)->index == b))
			return (pile[i]);
		else if ((pile + j)->index != EMPTY && ((pile + j)->index == a
				|| (pile + j)->index == b))
			return (pile[j]);
		i++;
		j--;
	}
	not_found.index = EMPTY;
	not_found.nbr = EMPTY;
	return (not_found);
}

t_elem	find_nearest_inrange(t_pushSwap piles, t_elem *pile, long min, long max)
{
	int		i;
	int		j;
	t_elem	not_found;

	i = skip_empty(piles, pile);
	j = piles.size - 1;
	while (i < piles.size)
	{
		if ((pile + i)->index != EMPTY && ((pile + i)->index >= min
				&& (pile + i)->index <= max))
			return (pile[i]);
		else if ((pile + j)->index != EMPTY && ((pile + j)->index >= min
				&& (pile + j)->index <= max))
			return (pile[j]);
		i++;
		j--;
	}
	not_found.index = EMPTY;
	not_found.nbr = EMPTY;
	return (not_found);
}
