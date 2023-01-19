/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_algos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:22:13 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/20 00:39:36 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_2_elements_a(t_pushSwap piles)
{
	int			i;

	i = piles.size - 2;
	if ((piles.a + i)->index > (piles.a + i + 1)->index)
		swap_a(piles);
}

void	algo_3_elements_a(t_pushSwap piles)
{
	int			i;
	t_numbers	numbers;

	numbers = define_properties(piles, piles.a);
	i = piles.size - 3;
	if ((piles.a + i)->index == numbers.smallest.index
		&& (piles.a + i + 1)->index != numbers.biggest.index)
		return ;
	else if (((piles.a + i)->index == numbers.smallest.index
			&& (piles.a + i + 1)->index == numbers.biggest.index)
		|| ((piles.a + i + 1)->index == numbers.smallest.index
			&& (piles.a + i + 2)->index == numbers.biggest.index))
		swap_a(piles);
	else if ((piles.a + i + 1)->index == numbers.biggest.index
		&& (piles.a + i + 2)->index == numbers.smallest.index)
		rev_rotate_a(piles);
	else
		rotate_a(piles);
	algo_3_elements_a(piles);
}

void	algo_19_elements_a(t_pushSwap piles)
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

void	algo_250_elements_a(t_pushSwap piles)
{
	long		i;
	long		count;
	long		best_i;
	long		best_count;

	i = 10;
	best_i = EMPTY;
	best_count = EMPTY;
	while (i < piles.size / 2 - 1)
	{
		algo_blocs(piles, i);
		optimise_operations(piles);
		count = count_operations(piles);
		if (count < best_count)
		{
			best_count = count;
			best_i = i;
		}
		reset_piles(piles);
		i++;
	}
	algo_blocs(piles, best_i);
}

void	algo_750_elements_a(t_pushSwap piles)
{
	long		i;
	long		count;
	long		best_i;
	long		best_count;

	i = 10;
	best_i = EMPTY;
	best_count = EMPTY;
	while (i < piles.size / 12)
	{
		algo_blocs(piles, i);
		optimise_operations(piles);
		count = count_operations(piles);
		if (count < best_count)
		{
			best_count = count;
			best_i = i;
		}
		reset_piles(piles);
		i++;
	}
	algo_blocs(piles, best_i);
}
