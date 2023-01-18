/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:32:07 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/18 15:57:26 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_a(t_pushSwap piles)
{
	int	i;
	int	j;

	i = 0;
	while (i < piles.size && ((piles.b) + i)->nbr == EMPTY)
		i++;
	if (i >= piles.size)
		return (0);
	j = 0;
	while (j + 1 < piles.size && ((piles.a) + j + 1)->nbr == EMPTY)
		j++;
	if (j >= piles.size)
		return (0);
	ft_swap(&(((piles.b) + i)->nbr), &((piles.a) + j)->nbr);
	ft_swap(&(((piles.b) + i)->index), &((piles.a) + j)->index);
	new_operation(piles, PA);
	return (1);
}

int	push_b(t_pushSwap piles)
{
	int	i;
	int	j;

	i = 0;
	while (i < piles.size && ((piles.a) + i)->nbr == EMPTY)
		i++;
	if (i >= piles.size)
		return (0);
	j = 0;
	while (j + 1 < piles.size && ((piles.b) + j + 1)->nbr == EMPTY)
		j++;
	if (j >= piles.size)
		return (0);
	ft_swap(&(((piles.a) + i)->nbr), &((piles.b) + j)->nbr);
	ft_swap(&(((piles.a) + i)->index), &((piles.b) + j)->index);
	new_operation(piles, PB);
	return (1);
}
