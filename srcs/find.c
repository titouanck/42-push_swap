/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:05:05 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/12 20:06:59 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	find_biggest(t_pushSwap piles, t_elem *pile)
{
	t_elem	biggest;
	int		i;

	biggest.index = -EMPTY;
	biggest.nbr = -EMPTY;
	i = 0;
	while (i < piles.size)
	{
		if ((pile + i)->index > biggest.index && (pile + i)->index != EMPTY)
			biggest = pile[i];
		i++;
	}
	return (biggest);
}