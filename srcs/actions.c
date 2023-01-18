/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:22:40 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/18 17:50:15 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

void	actions_smallest_on_top_a(t_pushSwap piles)
{
	push_b(piles);
}

void	actions_sec_smallest_on_top_a(t_pushSwap piles)
{
	t_numbers	numbers;

	push_b(piles);
	numbers = define_properties(piles, piles.a);
	place_element_on_top_a(piles, numbers.smallest);
	push_b(piles);
	swap_b(piles);
}

void	actions_biggest_on_top_a(t_pushSwap piles)
{
	push_b(piles);
	rotate_b(piles);
}
