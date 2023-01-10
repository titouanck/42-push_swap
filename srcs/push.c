/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:32:07 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/10 19:37:01 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#ifndef VISUALISATION

int	push_a(t_pushSwap piles)
{
	int	i;
	int	j;

	i = 0;
	while (((piles.b) + i)->nbr == EMPTY && i < piles.size)
		i++;
	if (i >= piles.size)
		return (0);
	j = 0;
	while (((piles.a) + j + 1)->nbr == EMPTY && j + 1 < piles.size)
		j++;
	if (j >= piles.size)
		return (0);
	ft_swap(&(((piles.b) + i)->nbr), &((piles.a) + j)->nbr);
	ft_swap(&(((piles.b) + i)->index), &((piles.a) + j)->index);
	return (ft_printf("pa\n"), 1);
}

int	push_b(t_pushSwap piles)
{
	int	i;
	int	j;

	i = 0;
	while (((piles.a) + i)->nbr == EMPTY && i < piles.size)
		i++;
	if (i >= piles.size)
		return (0);
	j = 0;
	while (((piles.b) + j + 1)->nbr == EMPTY && j + 1 < piles.size)
		j++;
	if (j >= piles.size)
		return (0);
	ft_swap(&(((piles.a) + i)->nbr), &((piles.b) + j)->nbr);
	ft_swap(&(((piles.a) + i)->index), &((piles.b) + j)->index);
	return (ft_printf("pb\n"), 1);
}

#endif

#ifdef VISUALISATION

int	push_a(t_pushSwap piles)
{
	int	i;
	int	j;

	i = 0;
	while (((piles.b) + i)->nbr == EMPTY && i < piles.size)
		i++;
	if (i >= piles.size)
		return (0);
	j = 0;
	while (((piles.a) + j + 1)->nbr == EMPTY && j + 1 < piles.size)
		j++;
	if (j >= piles.size)
		return (0);
	ft_swap(&(((piles.b) + i)->nbr), &((piles.a) + j)->nbr);
	ft_swap(&(((piles.b) + i)->index), &((piles.a) + j)->index);
	print_piles(piles);
	return (ft_printf("   pa\n"), 1);
}

int	push_b(t_pushSwap piles)
{
	int	i;
	int	j;

	i = 0;
	while (((piles.a) + i)->nbr == EMPTY && i < piles.size)
		i++;
	if (i >= piles.size)
		return (0);
	j = 0;
	while (((piles.b) + j + 1)->nbr == EMPTY && j + 1 < piles.size)
		j++;
	if (j >= piles.size)
		return (0);
	ft_swap(&(((piles.a) + i)->nbr), &((piles.b) + j)->nbr);
	ft_swap(&(((piles.a) + i)->index), &((piles.b) + j)->index);
	print_piles(piles);
	return (ft_printf("   pb\n"), 1);
}

#endif