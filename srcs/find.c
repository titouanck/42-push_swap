/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:07:40 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/04 18:38:11 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	find_smallest(t_pushSwap piles, long *pile)
{
	long	smallest;
	int		i;

	smallest = EMPTY;
	i = 0;
	while (i < piles.size)
	{
		if (pile[i] < smallest && pile[i] != EMPTY)
			smallest = pile[i];
		i++;
	}
	return (smallest);
}

long	*find_pile_start(t_pushSwap piles, long *pile)
{
	int		i;

	i = 0;
	while (i < piles.size)
	{
		if (pile[i] != EMPTY)
			return(pile + i);
		i++;
	}
	return (NULL);
}

long	find_elem_on_top(t_pushSwap piles, long *pile)
{
	int		i;

	i = 0;
	while (i < piles.size)
	{
		if (pile[i] != EMPTY)
			return(pile[i]);
		i++;
	}
	return (EMPTY);
}

long	find_sec_smallest(t_pushSwap piles, long *pile)
{
	long	smallest;
	long	sec_smallest;
	int		i;

	smallest = EMPTY;
	sec_smallest = EMPTY;
	i = 0;
	while (i < piles.size)
	{
		if (pile[i] < smallest && pile[i] != EMPTY)
		{
			sec_smallest = smallest;
			smallest = pile[i];	
		}
		else if (pile[i] < sec_smallest && pile[i] != EMPTY)
			sec_smallest = pile[i];
		i++;
	}
	return (sec_smallest);
}

long	find_biggest(t_pushSwap piles, long *pile)
{
	long	biggest;
	int		i;

	biggest = -EMPTY;
	i = 0;
	while (i < piles.size)
	{
		if (pile[i] > biggest && pile[i] != EMPTY)
			biggest = pile[i];
		i++;
	}
	return (biggest);
}

long	find_sec_biggest(t_pushSwap piles, long *pile)
{
	long	biggest;
	long	sec_biggest;
	int		i;

	biggest = -EMPTY;
	sec_biggest = -EMPTY;
	i = 0;
	while (i < piles.size)
	{
		if (pile[i] > biggest && pile[i] != EMPTY)
		{
			sec_biggest = biggest;
			biggest = pile[i];
		}
		else if (pile[i] > sec_biggest && pile[i] != EMPTY)
			sec_biggest = pile[i];
		i++;
	}
	return (sec_biggest);
}
