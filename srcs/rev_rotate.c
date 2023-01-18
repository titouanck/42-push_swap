/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:58:35 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/18 18:17:39 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rev_rotate_a(t_pushSwap piles)
{
	int		i;
	t_elem	tmp;

	i = piles.size - 1;
	tmp.nbr = ((piles.a) + i)->nbr;
	tmp.index = ((piles.a) + i)->index;
	if (!(i - 1 >= 0 && ((piles.a) + i - 1)->nbr != EMPTY))
		return (0);
	while (--i >= 0 && ((piles.a) + i)->nbr != EMPTY)
	{
		((piles.a) + i + 1)->nbr = ((piles.a) + i)->nbr;
		((piles.a) + i + 1)->index = ((piles.a) + i)->index;
	}
	if (i + 1 >= 0)
	{
		((piles.a) + i + 1)->nbr = tmp.nbr;
		((piles.a) + i + 1)->index = tmp.index;
	}
	new_operation(piles, RRA);
	return (1);
}

int	rev_rotate_b(t_pushSwap piles)
{
	int		i;
	t_elem	tmp;

	i = piles.size - 1;
	tmp.nbr = ((piles.b) + i)->nbr;
	tmp.index = ((piles.b) + i)->index;
	if (!(i - 1 >= 0 && ((piles.b) + i - 1)->nbr != EMPTY))
		return (0);
	while (--i >= 0 && ((piles.b) + i)->nbr != EMPTY)
	{
		((piles.b) + i + 1)->nbr = ((piles.b) + i)->nbr;
		((piles.b) + i + 1)->index = ((piles.b) + i)->index;
	}
	if (i + 1 >= 0)
	{
		((piles.b) + i + 1)->nbr = tmp.nbr;
		((piles.b) + i + 1)->index = tmp.index;
	}
	new_operation(piles, RRB);
	return (1);
}

static void	rev_rotate_ab_bis(t_pushSwap piles)
{
	int		i;
	t_elem	tmp;

	i = piles.size - 1;
	tmp.nbr = ((piles.b) + i)->nbr;
	tmp.index = ((piles.b) + i)->index;
	while (--i >= 0 && ((piles.b) + i)->nbr != EMPTY)
	{
		((piles.b) + i + 1)->nbr = ((piles.b) + i)->nbr;
		((piles.b) + i + 1)->index = ((piles.b) + i)->index;
	}	
	if (i + 1 >= 0)
	{
		((piles.b) + i + 1)->nbr = tmp.nbr;
		((piles.b) + i + 1)->index = tmp.index;
	}
}

int	rev_rotate_ab(t_pushSwap piles)
{
	int		i;
	t_elem	tmp;

	i = piles.size - 1;
	tmp.nbr = ((piles.a) + i)->nbr;
	tmp.index = ((piles.a) + i)->index;
	while (--i >= 0 && ((piles.a) + i)->nbr != EMPTY)
	{
		((piles.a) + i + 1)->nbr = ((piles.a) + i)->nbr;
		((piles.a) + i + 1)->index = ((piles.a) + i)->index;
	}
	if (i + 1 >= 0)
	{
		((piles.a) + i + 1)->nbr = tmp.nbr;
		((piles.a) + i + 1)->index = tmp.index;
	}
	rev_rotate_ab_bis(piles);
	return (new_operation(piles, RRR), 1);
}
