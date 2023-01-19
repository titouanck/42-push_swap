/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:05:05 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/20 00:46:32 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// t_elem	find_sec_ontop(t_pushSwap piles, t_elem *pile)
// {
// 	int		i;
// 	t_elem	notfound;

// 	i = 0;
// 	while (i + 1 < piles.size)
// 	{
// 		if ((pile + i)->index != EMPTY && (pile + i + 1)->index != EMPTY)
// 			return (pile[i + 1]);
// 		i++;
// 	}
// 	notfound.index = EMPTY;
// 	notfound.nbr = EMPTY;
// 	return (notfound);
// }

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

t_elem	find_sec_biggest(t_pushSwap piles, t_elem *pile)
{
	t_elem	biggest;
	t_elem	sec_biggest;
	int		i;

	biggest.index = -EMPTY;
	biggest.nbr = -EMPTY;
	sec_biggest.index = -EMPTY;
	sec_biggest.nbr = -EMPTY;
	i = 0;
	while (i < piles.size)
	{
		if ((pile + i)->index > biggest.index && (pile + i)->index != EMPTY)
		{
			sec_biggest = biggest;
			biggest = pile[i];
		}
		else if ((pile + i)->index > sec_biggest.index
			&& (pile + i)->index != EMPTY)
			sec_biggest = pile[i];
		i++;
	}
	return (sec_biggest);
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
		else if ((pile + i)->index < sec_smallest.index
			&& (pile + i)->index != EMPTY)
			sec_smallest = pile[i];
		i++;
	}
	return (sec_smallest);
}
