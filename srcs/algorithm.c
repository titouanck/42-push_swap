/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:57:40 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/17 20:02:06 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	algo_2_elements_a(t_pushSwap piles)
{
	int			i;
	t_numbers	numbers;

	numbers = define_properties(piles, piles.a);
	i = piles.size - 2;
	if ((piles.a + i)->index > (piles.a + i + 1)->index)
		swap_a(piles);
}

static void	algo_3_elements_a(t_pushSwap piles)
{
	int			i;
	t_numbers	numbers;

	numbers = define_properties(piles, piles.a);
	i = piles.size - 3;
	if ((piles.a + i)->index == numbers.smallest.index && (piles.a + i + 1)->index != numbers.biggest.index)
		return ;
	else if (((piles.a + i)->index == numbers.smallest.index && (piles.a + i + 1)->index == numbers.biggest.index)
		|| ((piles.a + i + 1)->index == numbers.smallest.index && (piles.a + i + 2)->index == numbers.biggest.index))
		swap_a(piles);
	else if ((piles.a + i + 1)->index == numbers.biggest.index && (piles.a + i + 2)->index == numbers.smallest.index)
		rev_rotate_a(piles);
	else
		rotate_a(piles);
	algo_3_elements_a(piles);
}

static void	algo_19_elements_a(t_pushSwap piles)
{
	t_numbers	numbers;

	while (pile_size(piles, piles.a) > 4)
	{
		numbers = define_properties(piles, piles.a);
		place_element_on_top_a(piles, numbers.nearest);
		if (numbers.nearest.index == numbers.smallest.index)
			actions_smallest_on_top_a(piles);
		else if (numbers.nearest.index == numbers.sec_smallest.index)
			actions_sec_smallest_on_top_a(piles);
	}
	if (pile_size(piles, piles.a) > 3)
	{
		numbers = define_properties(piles, piles.a);
		place_element_on_top_a(piles, numbers.smallest);
		actions_smallest_on_top_a(piles);
	}
	algo_3_elements_a(piles);
	while (pile_size(piles, piles.b) > 0)
		push_a(piles);
}

static void	algo_blocs_of_10(t_pushSwap piles)
{
	t_bloc		bloc_up;
	t_bloc		bloc_down;
	t_numbers	numbers_b;

	bloc_down.min = (piles.size / 2) / 10 * 10 - 10;
	bloc_down.max = bloc_down.min + 9;
	bloc_down.valid = 1;
	bloc_up.min = bloc_down.min + 10;
	bloc_up.max = bloc_up.min + 9;
	bloc_up.valid = 1;
	while (pile_size(piles, piles.a) > 0)
	{
		// printf("Bloc down: min (%ld) | max (%ld)\n", bloc_down.min, bloc_down.max);
		// printf("Bloc up: min (%ld) | max (%ld)\n", bloc_up.min, bloc_up.max);
		if (bloc_down.valid)
		{
			bloc_down.nearest = find_nearest_inrange(piles, piles.a, bloc_down.min, bloc_down.max);
			if (bloc_down.nearest.index == EMPTY)
			{
				bloc_down.min -= 10;
				bloc_down.max -= 10;
				if (bloc_down.min < 0)
					bloc_down.valid = 0;
				else
					bloc_down.nearest = find_nearest_inrange(piles, piles.a, bloc_down.min, bloc_down.max);
			}
		}
		if (bloc_up.valid)
		{
			bloc_up.nearest =  find_nearest_inrange(piles, piles.a, bloc_up.min, bloc_up.max);
			if (bloc_up.nearest.index == EMPTY)
			{
				bloc_up.min += 10;
				bloc_up.max += 10;
				if (bloc_up.min >= piles.size)
					bloc_up.valid = 0;
				else
				{					
					if (bloc_up.max >= piles.size)
						bloc_up.max = piles.size - 1;
					bloc_up.nearest =  find_nearest_inrange(piles, piles.a, bloc_up.min, bloc_up.max);
				}
			}
		}
		// printf("Bloc down: nearest (%ld)\n", bloc_down.nearest.index);
		// printf("Bloc up: nearest (%ld)\n", bloc_up.nearest.index);
		if (!(bloc_down.valid) && !(bloc_up.valid))
			break ;
		else if (bloc_down.valid && !(bloc_up.valid))
			place_element_on_top_a(piles, bloc_down.nearest);
		else if (bloc_up.valid && !(bloc_down.valid))
			place_element_on_top_a(piles, bloc_up.nearest);
		else
			place_element_on_top_a(piles, find_closest_one(piles, piles.a, bloc_down.nearest.index, bloc_up.nearest.index));
		push_b(piles);
		numbers_b = define_properties(piles, piles.b);
		if (numbers_b.ontop.index == bloc_down.nearest.index)
			rotate_b(piles);
	}
	while (pile_size(piles, piles.b) > 0)
	{
		place_element_on_top_b(piles, find_biggest(piles, piles.b));
		push_a(piles);
	}
}

void	algorithm(t_pushSwap piles)
{
	long		median;

	if (pile_size(piles, piles.a) == 0 || pile_size(piles, piles.a) == 1)
		return ;
	else if (pile_size(piles, piles.a) == 2)
		algo_2_elements_a(piles);
	else if (pile_size(piles, piles.a) == 3)
		algo_3_elements_a(piles);
	else if (pile_size(piles, piles.a) < 20)
		algo_19_elements_a(piles);
	else
		algo_blocs_of_10(piles);
}
