/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:32:07 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/04 18:56:49 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#ifndef VISUALISATION

int	push_a(t_pushSwap piles)
{
	int	i;
	int	j;

	i = 0;
	while ((piles.b)[i] == EMPTY && i < piles.size)
		i++;
	if (i >= piles.size)
		return (0);
	j = 0;
	while ((piles.a)[j + 1] == EMPTY && j + 1 < piles.size)
		j++;
	if (j >= piles.size)
		return (0);
	ft_swap(&((piles.b)[i]), &((piles.a)[j]));
	return (ft_printf("pa\n"), 1);
}

int	push_b(t_pushSwap piles)
{
	int	i;
	int	j;

	i = 0;
	while ((piles.a)[i] == EMPTY && i < piles.size)
		i++;
	if (i >= piles.size)
		return (0);
	j = 0;
	while ((piles.b)[j + 1] == EMPTY && j + 1 < piles.size)
		j++;
	if (j >= piles.size)
		return (0);
	ft_swap(&((piles.a)[i]), &((piles.b)[j]));
	return (ft_printf("pb\n"), 1);
}

#endif

#ifdef VISUALISATION

int	push_a(t_pushSwap piles)
{
	int	i;
	int	j;

	i = 0;
	while ((piles.b)[i] == EMPTY && i < piles.size)
		i++;
	if (i >= piles.size)
		return (0);
	j = 0;
	while ((piles.a)[j + 1] == EMPTY && j + 1 < piles.size)
		j++;
	if (j >= piles.size)
		return (0);
	ft_swap(&((piles.b)[i]), &((piles.a)[j]));
	print_piles(piles);
	return (ft_printf("   pa\n"), 1);
}

int	push_b(t_pushSwap piles)
{
	int	i;
	int	j;

	i = 0;
	while ((piles.a)[i] == EMPTY && i < piles.size)
		i++;
	if (i >= piles.size)
		return (0);
	j = 0;
	while ((piles.b)[j + 1] == EMPTY && j + 1 < piles.size)
		j++;
	if (j >= piles.size)
		return (0);
	ft_swap(&((piles.a)[i]), &((piles.b)[j]));
	print_piles(piles);
	return (ft_printf("   pb\n"), 1);
}

#endif