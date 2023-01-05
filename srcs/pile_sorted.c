/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_sorted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:29:28 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/05 16:30:19 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		pile_sorted(t_pushSwap piles, long *pile)
{
	int	i;

	i = 0;
	while (i < piles.size)
	{
		if (pile[i] != EMPTY)
			break ;
		i++;
	}
	while (i < piles.size)
	{			
		i++;
		if (i < piles.size && pile[i] < pile[i - 1])
			return (0);
	}
	return (1);
}