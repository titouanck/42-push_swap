/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:57:40 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/10 19:06:27 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algorithm(t_pushSwap piles)
{
	t_inPile	a;
	t_inPile	b;

	while (pile_size(piles, piles.a) > 0)
	{
		push_b(piles);
	}
}