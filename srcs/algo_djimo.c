/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_djimo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:33:24 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/05 14:33:42 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	actions_sec_smallest(t_pushSwap piles, t_inPile a, int called)
{
	define_properties_a(piles, &a);
	while (!called && a.nearest == a.biggest || a.nearest == a.sec_biggest)
	{
		if (a.nearest == a.biggest)
		{
			place_element_on_top_a(piles, a.nearest);
			push_b(piles);
			actions_biggest(piles);
		}
		else if (!called)
		{
			place_element_on_top_a(piles, a.nearest);
			push_b(piles);
			actions_sec_biggest(piles, a, 1);
		}
		else
			break ;
		define_properties_a(piles, &a);
	}
	smallest_on_top_a(piles, a.ptr, a);
	if (pile_sorted(piles, piles.a))
	{
		push_a(piles);
		swap_a(piles);
	}
	else
	{
		push_b(piles);
		swap_b(piles);
	}
}

void	actions_biggest(t_pushSwap piles)
{
	rotate_b(piles);
}

void	actions_sec_biggest(t_pushSwap piles, t_inPile a, int called)
{
	define_properties_a(piles, &a);
	while (!called && a.nearest == a.smallest)
	{
		place_element_on_top_a(piles, a.nearest);
		push_b(piles);
		swap_b(piles);
		define_properties_a(piles, &a);
	}
	biggest_on_top_a(piles, a.ptr, a);
	push_b(piles);
	rotate_b(piles);
	rotate_b(piles);
}

void	actions_third_smallest(t_pushSwap piles, t_inPile a, int called)
{
	define_properties_a(piles, &a);
	while (!called && a.nearest == a.biggest || a.nearest == a.sec_biggest)
	{
		place_element_on_top_a(piles, a.nearest);
		push_b(piles);
		if (a.nearest == a.biggest)
			actions_biggest(piles);
		else
			actions_sec_biggest(piles, a, 1);
		define_properties_a(piles, &a);
	}
	if (ssmallest_on_top_a(piles, a.ptr, a))
	{
		push_b(piles);
		swap_b(piles);
		define_properties_a(piles, &a);
		smallest_on_top_a(piles, a.ptr, a);
		push_b(piles);
		swap_b(piles);
	}
	else
	{
		rotate_b(piles);
		push_b(piles);
		define_properties_a(piles, &a);
		smallest_on_top_a(piles, a.ptr, a);
		push_b(piles);
		swap_b(piles);
		rev_rotate_b(piles);
	}
}

void	algorithm_djimo(t_pushSwap piles)
{
	t_inPile	a;
	t_inPile	b;

	while (1)
	{
		define_properties_a(piles, &a);
		if (a.elems == 0 || a.elems == 1 || pile_sorted(piles, piles.a))
			break ;
		else if (a.elems == 2)
			algo_2_elements_a(piles);
				else if (a.elems == 3)
			algo_3_elements_a(piles);
		if (a.elems == 2 || a.elems == 3)
			break ;
		place_element_on_top_a(piles, a.nearest);
		if (a.elems == 0 || a.elems == 1 || pile_sorted(piles, piles.a))
			break ;
		push_b(piles);
		if (a.nearest == a.sec_smallest)
			actions_sec_smallest(piles, a, 0);
		else if (a.nearest == a.biggest)
			actions_biggest(piles);
		else if (a.nearest == a.sec_biggest)
			actions_sec_biggest(piles, a, 0);
		else if (a.nearest == a.third_smallest)
			actions_third_smallest(piles, a, 0);
	}
	while (1)
	{
		define_properties_a(piles, &a);
		define_properties_b(piles, &b);
		if ((a.elems > 0 && b.on_top > a.on_top) || b.elems == 0)
			break ;
		push_a(piles);
	}
	while (1)
	{
		define_properties_a(piles, &a);
		define_properties_b(piles, &b);
		if (b.elems == 0)
			break ;
		rev_rotate_b(piles);
		push_a(piles);
		rotate_a(piles);
	}
}