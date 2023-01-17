/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:05:05 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/17 18:32:19 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_numbers	define_properties(t_pushSwap piles, t_elem *pile)
{
	t_numbers	numbers;

	numbers.smallest = find_smallest(piles, pile);
	numbers.sec_smallest = find_sec_smallest(piles, pile);
	numbers.biggest = find_biggest(piles, pile);
	numbers.ontop = find_ontop(piles, pile);
	numbers.nearest = find_nearest(piles, pile, numbers);
	return (numbers);
}

t_elem	find_ontop(t_pushSwap piles, t_elem *pile)
{
	int		i;
	t_elem	notfound;

	i = 0;
	while (i < piles.size)
	{
		if ((pile + i)->index != EMPTY)
			return (pile[i]);
		i++;
	}
	notfound.index = EMPTY;
	notfound.nbr = EMPTY;
	return (notfound);
}

t_elem	find_biggest(t_pushSwap piles, t_elem *pile)
{
	t_elem	biggest;
	int		i;

	biggest.index = -EMPTY;
	biggest.nbr = -EMPTY;
	i = 0;
	while (i < piles.size)
	{
		if ((pile + i)->index > biggest.index && (pile + i)->index != EMPTY)
			biggest = pile[i];
		i++;
	}
	return (biggest);
}

t_elem	find_smallest(t_pushSwap piles, t_elem *pile)
{
	t_elem	smallest;
	int		i;

	smallest.index = EMPTY;
	smallest.nbr = EMPTY;
	i = 0;
	while (i < piles.size)
	{
		if ((pile + i)->index < smallest.index && (pile + i)->index != EMPTY)
			smallest = pile[i];
		i++;
	}
	return (smallest);
}

t_elem	find_sec_smallest(t_pushSwap piles, t_elem *pile)
{
	t_elem	smallest;
	t_elem	sec_smallest;
	int		i;

	smallest.index = EMPTY;
	smallest.nbr = EMPTY;
	sec_smallest.index = EMPTY;
	sec_smallest.nbr = EMPTY;
	i = 0;
	while (i < piles.size)
	{
		if ((pile + i)->index < smallest.index && (pile + i)->index != EMPTY)
		{
			sec_smallest = smallest;
			smallest = pile[i];
		}
		else if ((pile + i)->index < sec_smallest.index && (pile + i)->index != EMPTY)
			sec_smallest = pile[i];
		i++;
	}
	return (sec_smallest);
}

t_elem	find_nearest(t_pushSwap piles, t_elem *pile, t_numbers numbers)
{
	int		i;
	int		j;
	t_elem	not_found;

	i = 0;
	j = piles.size - 1;
	while (i < piles.size)
	{
		if ((pile + i)->index != EMPTY && (pile + i)->index == (numbers.smallest).index)
			return (numbers.smallest);
		else if ((pile + j)->index != EMPTY && (pile + j)->index == (numbers.smallest).index)
			return (numbers.smallest);

		else if (i + 1 < piles.size && (pile + i + 1)->index != EMPTY && (pile + i + 1)->index == (numbers.smallest).index)
			return (numbers.smallest);
		else if (j - 1 >= 0 && (pile + j + 1)->index != EMPTY && (pile + j + 1)->index == (numbers.smallest).index)
			return (numbers.smallest);

		if ((pile + i)->index != EMPTY && (pile + i)->index == (numbers.sec_smallest).index)
			return (numbers.sec_smallest);
		else if ((pile + j)->index != EMPTY && (pile + j)->index == (numbers.sec_smallest).index)
			return (numbers.sec_smallest);
			
			
		// else if ((pile + i)->index != EMPTY && (pile + i)->index == (numbers.biggest).index)
		// 	return (numbers.biggest);
		// else if ((pile + j)->index != EMPTY && (pile + j)->index == (numbers.biggest).index)
		// 	return (numbers.biggest);
			
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
	j = piles.size - 1;
	while (i < piles.size)
	{
		if ((pile + i)->index != EMPTY && ((pile + i)->index == a || (pile + i)->index == b))
			return (pile[i]);
		else if ((pile + j)->index != EMPTY && ((pile + j)->index == a || (pile + j)->index == b))
			return (pile[j]);
		i++;
		j++;
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
