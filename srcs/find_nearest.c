/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_nearest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:53:46 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/18 17:54:06 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	find_nearest(t_pushSwap piles, t_elem *pile, t_numbers numbers)
{
	int		i;
	int		j;
	t_elem	not_found;

	i = 0;
	while (i < piles.size && (pile + i)->index == EMPTY)
		i++;
	j = piles.size - 1;
	while (i < piles.size)
	{
		if ((pile + i)->index != EMPTY && (pile + i)->index == (numbers.smallest).index)
			return (numbers.smallest);
		else if ((pile + j)->index != EMPTY && (pile + j)->index == (numbers.smallest).index)
			return (numbers.smallest);

		else if (i + 1 < piles.size && (pile + i + 1)->index != EMPTY && (pile + i + 1)->index == (numbers.smallest).index)
			return (numbers.smallest);
		else if (j - 1 >= 0 && (pile + j - 1)->index != EMPTY && (pile + j - 1)->index == (numbers.smallest).index)
			return (numbers.smallest);

		else if ((pile + i)->index != EMPTY && (pile + i)->index == (numbers.sec_smallest).index)
			return (numbers.sec_smallest);
		else if ((pile + j)->index != EMPTY && (pile + j)->index == (numbers.sec_smallest).index)
			return (numbers.sec_smallest);
			
		i++;
		j--;
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

	i = 0;
	while (i < piles.size && (pile + i)->index == EMPTY)
		i++;
	j = piles.size - 1;
	while (i < piles.size)
	{
		if ((pile + i)->index != EMPTY && ((pile + i)->index == a || (pile + i)->index == b))
			return (pile[i]);
		else if ((pile + j)->index != EMPTY && ((pile + j)->index == a || (pile + j)->index == b))
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

	i = 0;
	while (i < piles.size && (pile + i)->index == EMPTY)
		i++;
	j = piles.size - 1;
	while (i < piles.size)
	{
		if ((pile + i)->index != EMPTY && ((pile + i)->index >= min && (pile + i)->index <= max))
			return (pile[i]);
		else if ((pile + j)->index != EMPTY && ((pile + j)->index >= min && (pile + j)->index <= max))
			return (pile[j]);
		i++;
		j--;
	}
	not_found.index = EMPTY;
	not_found.nbr = EMPTY;
	return (not_found);
}
