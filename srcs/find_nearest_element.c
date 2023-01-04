/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_nearest_element.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:45:19 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/04 17:49:05 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	find_nearest_element_a(t_pushSwap piles, t_inPile nbr)
{
	int	i;

	i = 0;
	while ((piles.a)[i] == EMPTY)
		i++;
	while (i < piles.size)
	{
		if ((piles.a)[i] == nbr.smallest || (piles.a)[i] == nbr.sec_smallest)
			return ((piles.a)[i]);
		else if (i + 1 < piles.size && ((piles.a)[i + 1] == nbr.smallest
			|| (piles.a)[i + 1] == nbr.sec_smallest))
			return ((piles.a)[i + 1]);
		else if (i + 2 < piles.size && (piles.a)[i + 2] == nbr.smallest)
			return ((piles.a)[i + 2]);
		else if ((piles.a)[i] == nbr.biggest || (piles.a)[i] == nbr.sec_biggest)
			return ((piles.a)[i]);
		i++;
	}
	return (EMPTY);
}