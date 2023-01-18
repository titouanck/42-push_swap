/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_properties.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:52:46 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/18 17:52:53 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_numbers	define_properties(t_pushSwap piles, t_elem *pile)
{
	t_numbers	numbers;

	numbers.smallest = find_smallest(piles, pile);
	numbers.sec_smallest = find_sec_smallest(piles, pile);
	numbers.biggest = find_biggest(piles, pile);
	numbers.sec_biggest = find_sec_biggest(piles, pile);
	numbers.ontop = find_ontop(piles, pile);
	numbers.nearest = find_nearest(piles, pile, numbers);
	return (numbers);
}