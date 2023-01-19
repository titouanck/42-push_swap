/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_blocs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:37:16 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/20 00:38:35 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	algo_blocdown_valid(t_pushSwap piles, int nbr, t_bloc *bloc_down)
{
	bloc_down->nearest = \
	find_nearest_inrange(piles, piles.a, bloc_down->min, bloc_down->max);
	if (bloc_down->nearest.index == EMPTY)
	{
		bloc_down->min -= nbr;
		bloc_down->max -= nbr;
		if (bloc_down->min < 0)
			bloc_down->valid = 0;
		else
			bloc_down->nearest = \
	find_nearest_inrange(piles, piles.a, bloc_down->min, bloc_down->max);
	}
}

static void	algo_blocup_valid(t_pushSwap piles, int nbr, t_bloc *bloc_up)
{
	bloc_up->nearest = \
	find_nearest_inrange(piles, piles.a, bloc_up->min, bloc_up->max);
	if (bloc_up->nearest.index == EMPTY)
	{
		bloc_up->min += nbr;
		bloc_up->max += nbr;
		if (bloc_up->min >= piles.size)
			bloc_up->valid = 0;
		else
		{					
			if (bloc_up->max >= piles.size)
				bloc_up->max = piles.size - 1;
			bloc_up->nearest = \
	find_nearest_inrange(piles, piles.a, bloc_up->min, bloc_up->max);
		}
	}
}

static void	algo_bloc_part1(t_pushSwap piles, int nbr, \
	t_bloc *bloc_up, t_bloc *bloc_down)
{
	t_numbers	numbers_b;

	if (bloc_down->valid)
		algo_blocdown_valid(piles, nbr, bloc_down);
	if (bloc_up->valid)
		algo_blocup_valid(piles, nbr, bloc_up);
	if (!(bloc_down->valid) && !(bloc_up->valid))
		return ;
	else if (bloc_down->valid && !(bloc_up->valid))
		place_element_on_top_a(piles, bloc_down->nearest);
	else if (bloc_up->valid && !(bloc_down->valid))
		place_element_on_top_a(piles, bloc_up->nearest);
	else
		place_element_on_top_a(piles, find_closest_one(piles, piles.a, \
bloc_down->nearest.index, bloc_up->nearest.index));
	push_b(piles);
	numbers_b = define_properties(piles, piles.b);
	if (numbers_b.ontop.index == bloc_down->nearest.index)
		rotate_b(piles);
}

void	algo_blocs(t_pushSwap piles, int nbr)
{
	t_bloc		bloc_up;
	t_bloc		bloc_down;
	t_numbers	numbers_b;

	bloc_down = define_bloc_down(piles, nbr);
	bloc_up = define_bloc_up(nbr, bloc_down);
	while (pile_size(piles, piles.a) > 0)
		algo_bloc_part1(piles, nbr, &bloc_up, &bloc_down);
	while (pile_size(piles, piles.b) > 0)
	{
		numbers_b = define_properties(piles, piles.b);
		numbers_b.nearest = find_closest_one(piles, piles.b, \
	numbers_b.biggest.index, numbers_b.sec_biggest.index);
		place_element_on_top_b(piles, numbers_b.nearest);
		push_a(piles);
		if (numbers_b.nearest.index == numbers_b.sec_biggest.index)
		{
			place_element_on_top_b(piles, numbers_b.biggest);
			push_a(piles);
			swap_a(piles);
		}
	}
}
