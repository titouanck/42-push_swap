/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_properties.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:31:56 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/07 16:11:40 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	define_properties_a(t_pushSwap piles, t_inPile *a)
{
	a->elems = pile_size(piles, piles.a);
	if (a->elems > 0)
	{
		a->ptr = find_pile_start(piles, piles.a);
		a->on_top = find_elem_on_top(piles, piles.a);
		a->smallest = find_smallest(piles, piles.a);
		a->sec_smallest = find_sec_smallest(piles, piles.a);
		a->third_smallest = find_third_smallest(piles, piles.a);
		a->biggest = find_biggest(piles, piles.a);
		a->sec_biggest = find_sec_biggest(piles, piles.a);
		a->nearest = find_nearest_element_a(piles, *a);
	}
}

void	define_properties_b(t_pushSwap piles, t_inPile *b)
{
	b->elems = pile_size(piles, piles.b);
	if (b->elems > 0)
	{
		b->ptr = find_pile_start(piles, piles.b);
		b->on_top = find_elem_on_top(piles, piles.b);
		b->smallest = find_smallest(piles, piles.b);
		b->third_smallest = find_third_smallest(piles, piles.b);
		b->biggest = find_biggest(piles, piles.b);
		b->sec_biggest = find_sec_biggest(piles, piles.b);
	}
}