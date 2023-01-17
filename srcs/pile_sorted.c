/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_sorted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:36:21 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/17 15:39:28 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		pile_sorted(t_pushSwap piles, t_elem *pile)
{
	int	i;

	i = 0;
	while (i < piles.size)
	{
		if ((pile + i)->index != EMPTY)
			break ;
		i++;
	}
	while (i < piles.size)
	{			
		i++;
		if (i < piles.size && (pile + i)->index < (pile + i - 1)->index)
			return (0);
	}
	return (1);
}