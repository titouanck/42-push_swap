/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:31:28 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/18 15:56:43 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_a(t_pushSwap piles)
{
	int	i;

	i = 0;
	while (((piles.a) + i)->nbr == EMPTY && i + 1 < piles.size)
		i++;
	if (i + 1 < piles.size)
	{
		ft_swap(&(((piles.a) + i)->nbr), &((piles.a) + i + 1)->nbr);
		ft_swap(&(((piles.a) + i)->index), &((piles.a) + i + 1)->index);
	}
	else
		return (0);
	new_operation(piles, SA);
	return (1);
}

int	swap_b(t_pushSwap piles)
{
	int	i;

	i = 0;
	while (((piles.b) + i)->nbr == EMPTY && i + 1 < piles.size)
		i++;
	if (i + 1 < piles.size)
	{
		ft_swap(&(((piles.b) + i)->nbr), &((piles.b) + i + 1)->nbr);
		ft_swap(&(((piles.b) + i)->index), &((piles.b) + i + 1)->index);
	}
	else
		return (0);
	new_operation(piles, SB);
	return (1);
}

int	swap_ab(t_pushSwap piles)
{
	int	i;

	i = 0;
	while (((piles.a) + i)->nbr == EMPTY && i + 1 < piles.size)
		i++;
	if (i + 1 < piles.size)
		ft_swap(&(((piles.a) + i)->nbr), &((piles.a) + i + 1)->nbr);
	i = 0;
	while (((piles.b) + i)->nbr == EMPTY && i + 1 < piles.size)
		i++;
	if (i + 1 < piles.size)
	{
		ft_swap(&(((piles.b) + i)->nbr), &((piles.b) + i + 1)->nbr);
		ft_swap(&(((piles.b) + i)->index), &((piles.b) + i + 1)->index);
	}
	new_operation(piles, SS);
	return (1);
}
