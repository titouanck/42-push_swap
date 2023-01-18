/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:57:40 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/18 18:37:32 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algorithm(t_pushSwap piles)
{
	if (pile_size(piles, piles.a) == 0 || pile_size(piles, piles.a) == 1)
		return ;
	else if (pile_size(piles, piles.a) == 2)
		algo_2_elements_a(piles);
	else if (pile_size(piles, piles.a) == 3)
		algo_3_elements_a(piles);
	else if (pile_size(piles, piles.a) < 20)
		algo_19_elements_a(piles);
	else if (pile_size(piles, piles.a) < 101)
		algo_100_elements_a(piles);
	else if (pile_size(piles, piles.a) < 751)
		algo_750_elements_a(piles);
	else
		algo_blocs(piles, 50);
	free(piles.a);
	free(piles.b);
}
