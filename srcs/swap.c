/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:31:28 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/08 16:27:00 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#ifndef VISUALISATION

int	swap_a(t_pushSwap piles)
{
	int	i;

	i = 0;
	while ((piles.a)[i] == EMPTY && i + 1 < piles.size)
		i++;
	if (i + 1 < piles.size)
		ft_swap(&((piles.a)[i]), &((piles.a)[i + 1]));
	else
		return (0);
	return (action_lstaddback(piles, 1), 1);
}

int	swap_b(t_pushSwap piles)
{
	int	i;

	i = 0;
	while ((piles.b)[i] == EMPTY && i + 1 < piles.size)
		i++;
	if (i + 1 < piles.size)
		ft_swap(&((piles.b)[i]), &((piles.b)[i + 1]));
	else
		return (0);
	return (action_lstaddback(piles, 2), 1);
}

int	swap_ab(t_pushSwap piles)
{
	int	i;

	i = 0;
	while ((piles.a)[i] == EMPTY && i + 1 < piles.size)
		i++;
	if (i + 1 < piles.size)
		ft_swap(&((piles.a)[i]), &((piles.a)[i + 1]));
	i = 0;
	while ((piles.b)[i] == EMPTY && i + 1 < piles.size)
		i++;
	if (i + 1 < piles.size)
		ft_swap(&((piles.b)[i]), &((piles.b)[i + 1]));
	action_lstaddback(piles, 3);
	return (action_lstaddback(piles, 3), 1);
}

#endif

#ifdef VISUALISATION

int	swap_a(t_pushSwap piles)
{
	int	i;

	i = 0;
	while ((piles.a)[i] == EMPTY && i + 1 < piles.size)
		i++;
	if (i + 1 < piles.size)
		ft_swap(&((piles.a)[i]), &((piles.a)[i + 1]));
	else
		return (0);
	print_piles(piles);
	return (ft_printf("   sa\n"), 1);
}

int	swap_b(t_pushSwap piles)
{
	int	i;

	i = 0;
	while ((piles.b)[i] == EMPTY && i + 1 < piles.size)
		i++;
	if (i + 1 < piles.size)
		ft_swap(&((piles.b)[i]), &((piles.b)[i + 1]));
	else
		return (0);
	print_piles(piles);
	return (ft_printf("   sb\n"), 1);
}

int	swap_ab(t_pushSwap piles)
{
	int	i;

	i = 0;
	while ((piles.a)[i] == EMPTY && i + 1 < piles.size)
		i++;
	if (i + 1 < piles.size)
		ft_swap(&((piles.a)[i]), &((piles.a)[i + 1]));
	i = 0;
	while ((piles.b)[i] == EMPTY && i + 1 < piles.size)
		i++;
	if (i + 1 < piles.size)
		ft_swap(&((piles.b)[i]), &((piles.b)[i + 1]));
	print_piles(piles);
	return (ft_printf("   ss\n"), 1);
}

#endif