/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:57:40 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/18 15:47:33 by tchevrie         ###   ########.fr       */
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
		numbers_b = define_properties(piles, piles.b);
		numbers_b.nearest = find_closest_one(piles, piles.b, numbers_b.biggest.index, numbers_b.sec_biggest.index);
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

static void	algo_blocs_of_12(t_pushSwap piles)
{
	t_bloc		bloc_up;
	t_bloc		bloc_down;
	t_numbers	numbers_b;

	bloc_down.min = (piles.size / 2) / 12 * 12 - 12;
	bloc_down.max = bloc_down.min + 11;
	bloc_down.valid = 1;
	bloc_up.min = bloc_down.min + 12;
	bloc_up.max = bloc_up.min + 11;
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
				bloc_down.min -= 12;
				bloc_down.max -= 12;
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
				bloc_up.min += 12;
				bloc_up.max += 12;
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
		numbers_b = define_properties(piles, piles.b);
		numbers_b.nearest = find_closest_one(piles, piles.b, numbers_b.biggest.index, numbers_b.sec_biggest.index);
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

static void	algo_blocs_of_13(t_pushSwap piles)
{
	t_bloc		bloc_up;
	t_bloc		bloc_down;
	t_numbers	numbers_b;

	bloc_down.min = (piles.size / 2) / 13 * 13 - 13;
	bloc_down.max = bloc_down.min + 12;
	bloc_down.valid = 1;
	bloc_up.min = bloc_down.min + 13;
	bloc_up.max = bloc_up.min + 12;
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
				bloc_down.min -= 13;
				bloc_down.max -= 13;
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
				bloc_up.min += 13;
				bloc_up.max += 13;
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
		numbers_b = define_properties(piles, piles.b);
		numbers_b.nearest = find_closest_one(piles, piles.b, numbers_b.biggest.index, numbers_b.sec_biggest.index);
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

static void	algo_blocs_of_14(t_pushSwap piles)
{
	t_bloc		bloc_up;
	t_bloc		bloc_down;
	t_numbers	numbers_b;

	bloc_down.min = (piles.size / 2) / 14 * 14 - 14;
	bloc_down.max = bloc_down.min + 13;
	bloc_down.valid = 1;
	bloc_up.min = bloc_down.min + 14;
	bloc_up.max = bloc_up.min + 13;
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
				bloc_down.min -= 14;
				bloc_down.max -= 14;
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
				bloc_up.min += 14;
				bloc_up.max += 14;
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
		numbers_b = define_properties(piles, piles.b);
		numbers_b.nearest = find_closest_one(piles, piles.b, numbers_b.biggest.index, numbers_b.sec_biggest.index);
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

static void	algo_blocs_of_15(t_pushSwap piles)
{
	t_bloc		bloc_up;
	t_bloc		bloc_down;
	t_numbers	numbers_b;

	bloc_down.min = (piles.size / 2) / 15 * 15 - 15;
	bloc_down.max = bloc_down.min + 14;
	bloc_down.valid = 1;
	bloc_up.min = bloc_down.min + 15;
	bloc_up.max = bloc_up.min + 14;
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
				bloc_down.min -= 15;
				bloc_down.max -= 15;
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
				bloc_up.min += 15;
				bloc_up.max += 15;
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
		numbers_b = define_properties(piles, piles.b);
		numbers_b.nearest = find_closest_one(piles, piles.b, numbers_b.biggest.index, numbers_b.sec_biggest.index);
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

static void	algo_blocs_of_20(t_pushSwap piles)
{
	t_bloc		bloc_up;
	t_bloc		bloc_down;
	t_numbers	numbers_b;

	bloc_down.min = (piles.size / 2) / 20 * 20 - 20;
	bloc_down.max = bloc_down.min + 19;
	bloc_down.valid = 1;
	bloc_up.min = bloc_down.min + 20;
	bloc_up.max = bloc_up.min + 19;
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
				bloc_down.min -= 20;
				bloc_down.max -= 20;
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
				bloc_up.min += 20;
				bloc_up.max += 20;
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
		numbers_b = define_properties(piles, piles.b);
		numbers_b.nearest = find_closest_one(piles, piles.b, numbers_b.biggest.index, numbers_b.sec_biggest.index);
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

static void	algo_blocs_of_30(t_pushSwap piles)
{
	t_bloc		bloc_up;
	t_bloc		bloc_down;
	t_numbers	numbers_b;

	bloc_down.min = (piles.size / 2) / 30 * 30 - 30;
	bloc_down.max = bloc_down.min + 29;
	bloc_down.valid = 1;
	bloc_up.min = bloc_down.min + 30;
	bloc_up.max = bloc_up.min + 29;
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
				bloc_down.min -= 30;
				bloc_down.max -= 30;
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
				bloc_up.min += 30;
				bloc_up.max += 30;
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
		numbers_b = define_properties(piles, piles.b);
		numbers_b.nearest = find_closest_one(piles, piles.b, numbers_b.biggest.index, numbers_b.sec_biggest.index);
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
	else if (pile_size(piles, piles.a) < 30)
		algo_blocs_of_10(piles);
	else if (pile_size(piles, piles.a) < 150)
		algo_blocs_of_15(piles);
	else
		algo_blocs_of_30(piles);
}

/*
=======> RESULTS <=======
1       |  OK  | 0
2       |  OK  | 1
3       |  OK  | 2
4       |  OK  | 5
5       |  OK  | 7
10      |  OK  | 28
15      |  OK  | 55
20      |  OK  | 75
30      |  OK  | 107
50      |  OK  | 243
100 (1) |  OK  | 599
100 (2) |  OK  | 718
100 (3) |  OK  | 619
100 (4) |  OK  | 606
100 (5) |  OK  | 341
100 (6) |  OK  | 593
100 (7) |  OK  | 659
100 (8) |  OK  | 620
500     |  OK  | 5596
1000    |  OK  | 16402*/