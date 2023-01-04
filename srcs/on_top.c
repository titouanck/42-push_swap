/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_top.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:54:24 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/04 16:37:27 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	in_superior_part(t_pushSwap piles, long *pile, long elem)
{
	int	i;
	int	count;

	i = 0;
	while (i < piles.size)
	{
		if (pile[i] != EMPTY)
			break ;
		i++;
	}
	count = 0;
	while (i < piles.size)
	{
		if (pile[i] == elem)
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

void	smallest_on_top_a(t_pushSwap piles, long *pile, t_inPile number)
{
	number.sec_smallest = find_sec_smallest(piles, piles.a);
	while (*pile != number.smallest)
	{
		if (pile[1] == number.smallest && pile[0] == number.sec_smallest)
			swap_a(piles);
		else if (in_superior_part(piles, piles.a, number.smallest))
			rotate_a(piles);
		else
			rev_rotate_a(piles);
		
	}
}

int	ssmallest_on_top_a(t_pushSwap piles, long *pile, t_inPile number)
{
	int	i;

	i = 0;
	number.sec_smallest = find_sec_smallest(piles, piles.a);
	while (pile[i] != number.smallest && pile[i] != number.sec_smallest
		&& (piles.a)[piles.size - i - 1] != number.smallest
		&& (piles.a)[piles.size - i - 1] != number.sec_smallest)
			i++;
	number.to_find = number.smallest;
	if (pile[i] != number.smallest
		&& (piles.a)[piles.size - i - 1] != number.smallest)
		number.to_find = number.sec_smallest;
	while (*pile != number.smallest && *pile != number.sec_smallest)
	{
		if (pile[1] == number.smallest && pile[0] == number.sec_smallest)
			swap_a(piles);
		else if (in_superior_part(piles, piles.a, number.to_find))
			rotate_a(piles);
		else
			rev_rotate_a(piles);
	}
	if (*pile == number.smallest)
		return (1);
	return (0);
}

void	biggest_on_top_b(t_pushSwap piles, long *pile, t_inPile number)
{
	number.sec_biggest = find_sec_biggest(piles, piles.b);
	while (*pile != number.biggest)
	{
		if (pile[1] == number.biggest && pile[0] == number.sec_biggest)
			swap_b(piles);
		else if (in_superior_part(piles, piles.b, number.biggest))
			rotate_b(piles);
		else
			rev_rotate_b(piles);
	}
}
