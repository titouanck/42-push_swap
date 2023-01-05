/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_nearest_element.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:45:19 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/05 17:00:43 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	find_nearest_element_a(t_pushSwap piles, t_inPile nbr)
{
	int	i;
	int	j;

	i = 0;
	while ((piles.a)[i] == EMPTY)
		i++;
	j = piles.size - 1;
	while (i < piles.size && j >= 0)
	{
		if ((piles.a)[i] == nbr.smallest)
			return ((piles.a)[i]);
		else if ((piles.a)[j] == nbr.smallest)
			return ((piles.a)[j]);
		else if ((piles.a)[i] == nbr.sec_smallest)
			return ((piles.a)[i]);
		else if ((piles.a)[j] == nbr.sec_smallest)
			return ((piles.a)[j]);
		else if (i + 1 < piles.size && (piles.a)[i + 1] == nbr.sec_smallest)
			return ((piles.a)[i + 1]);
		else if (j - 1 >= 0 && (piles.a)[j - 1] == nbr.sec_smallest)
			return ((piles.a)[j - 1]);
		else if ((piles.a)[i] == nbr.biggest)
			return ((piles.a)[i]);
		else if ((piles.a)[j] == nbr.biggest)
			return ((piles.a)[j]);
		else if ((piles.a)[i] == nbr.sec_biggest)
			return ((piles.a)[i]);
		else if ((piles.a)[j] == nbr.sec_biggest)
			return ((piles.a)[j]);
		i++;
		j--;
	}
	return (EMPTY);
}