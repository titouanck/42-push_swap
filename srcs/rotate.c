/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:53:53 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/18 18:18:44 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_a(t_pushSwap piles)
{
	int		i;
	t_elem	tmp;

	i = 0;
	while (((piles.a) + i)->nbr == EMPTY && i + 1 < piles.size)
		i++;
	tmp.nbr = ((piles.a) + i)->nbr;
	tmp.index = ((piles.a) + i)->index;
	if (i + 1 >= piles.size)
		return (0);
	while (++i < piles.size)
	{
		((piles.a) + i - 1)->nbr = ((piles.a) + i)->nbr;
		((piles.a) + i - 1)->index = ((piles.a) + i)->index;
	}
	if (i - 1 < piles.size)
	{
		((piles.a) + i - 1)->nbr = tmp.nbr;
		((piles.a) + i - 1)->index = tmp.index;
	}
	new_operation(piles, RA);
	return (1);
}

int	rotate_b(t_pushSwap piles)
{
	int		i;
	t_elem	tmp;

	i = 0;
	while (((piles.b) + i)->nbr == EMPTY && i + 1 < piles.size)
		i++;
	tmp.nbr = ((piles.b) + i)->nbr;
	tmp.index = ((piles.b) + i)->index;
	if (i + 1 >= piles.size)
		return (0);
	while (++i < piles.size)
	{
		((piles.b) + i - 1)->nbr = ((piles.b) + i)->nbr;
		((piles.b) + i - 1)->index = ((piles.b) + i)->index;
	}
	if (i - 1 < piles.size)
	{
		((piles.b) + i - 1)->nbr = tmp.nbr;
		((piles.b) + i - 1)->index = tmp.index;
	}
	new_operation(piles, RB);
	return (1);
}

static void	rotate_ab_bis(t_pushSwap piles)
{
	int		i;
	t_elem	tmp;

	i = 0;
	while (((piles.b) + i)->nbr == EMPTY && i + 1 < piles.size)
		i++;
	tmp.nbr = ((piles.b) + i)->nbr;
	tmp.index = ((piles.b) + i)->index;
	while (++i < piles.size)
	{
		((piles.b) + i - 1)->nbr = ((piles.b) + i)->nbr;
		((piles.b) + i - 1)->index = ((piles.b) + i)->index;
	}
	if (i - 1 < piles.size)
	{
		((piles.b) + i - 1)->nbr = tmp.nbr;
		((piles.b) + i - 1)->index = tmp.index;
	}
}

int	rotate_ab(t_pushSwap piles)
{
	int		i;
	t_elem	tmp;

	i = 0;
	while (((piles.a) + i)->nbr == EMPTY && i + 1 < piles.size)
		i++;
	tmp.nbr = ((piles.a) + i)->nbr;
	tmp.index = ((piles.a) + i)->index;
	while (++i < piles.size)
	{
		((piles.a) + i - 1)->nbr = ((piles.a) + i)->nbr;
		((piles.a) + i - 1)->index = ((piles.a) + i)->index;
	}
	if (i - 1 < piles.size)
	{
		((piles.a) + i - 1)->nbr = tmp.nbr;
		((piles.a) + i - 1)->index = tmp.index;
	}
	rotate_ab_bis(piles);
	return (new_operation(piles, RR), 1);
}
