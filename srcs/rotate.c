/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:53:53 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/08 16:28:07 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#ifndef VISUALISATION

int	rotate_a(t_pushSwap piles)
{
	int		i;
	long	tmp;

	i = 0;
	while ((piles.a)[i] == EMPTY && i + 1 < piles.size)
		i++;
	tmp = (piles.a)[i];
	if (i + 1 >= piles.size)
		return (0);
	while (++i < piles.size)
		(piles.a)[i - 1] = (piles.a)[i];
	if (i - 1 < piles.size)
		(piles.a)[i - 1] = tmp;
	return (action_lstaddback(piles, 6), 1);
}

int	rotate_b(t_pushSwap piles)
{
	int		i;
	long	tmp;

	i = 0;
	while ((piles.b)[i] == EMPTY && i + 1 < piles.size)
		i++;
	tmp = (piles.b)[i];
	if (i + 1 >= piles.size)
		return (0);
	while (++i < piles.size)
		(piles.b)[i - 1] = (piles.b)[i];
	if (i - 1 < piles.size)
		(piles.b)[i - 1] = tmp;
	return (action_lstaddback(piles, 7), 1);
}

int	rotate_ab(t_pushSwap piles)
{
	int		i;
	long	tmp;

	i = 0;
	while ((piles.a)[i] == EMPTY && i + 1 < piles.size)
		i++;
	tmp = (piles.a)[i];
	while (++i < piles.size)
		(piles.a)[i - 1] = (piles.a)[i];
	if (i - 1 < piles.size)
		(piles.a)[i - 1] = tmp;
	i = 0;
	while ((piles.b)[i] == EMPTY && i + 1 < piles.size)
		i++;
	tmp = (piles.b)[i];
	while (++i < piles.size)
		(piles.b)[i - 1] = (piles.b)[i];
	if (i - 1 < piles.size)
		(piles.b)[i - 1] = tmp;
	return (action_lstaddback(piles, 8), 1);
}

#endif

#ifdef VISUALISATION

int	rotate_a(t_pushSwap piles)
{
	int		i;
	long	tmp;

	i = 0;
	while ((piles.a)[i] == EMPTY && i + 1 < piles.size)
		i++;
	tmp = (piles.a)[i];
	if (i + 1 >= piles.size)
		return (0);
	while (++i < piles.size)
		(piles.a)[i - 1] = (piles.a)[i];
	if (i - 1 < piles.size)
		(piles.a)[i - 1] = tmp;
	print_piles(piles);
	return (ft_printf("   ra\n"), 1);
}

int	rotate_b(t_pushSwap piles)
{
	int		i;
	long	tmp;

	i = 0;
	while ((piles.b)[i] == EMPTY && i + 1 < piles.size)
		i++;
	tmp = (piles.b)[i];
	if (i + 1 >= piles.size)
		return (0);
	while (++i < piles.size)
		(piles.b)[i - 1] = (piles.b)[i];
	if (i - 1 < piles.size)
		(piles.b)[i - 1] = tmp;
	print_piles(piles);
	return (ft_printf("   rb\n"), 1);
}

int	rotate_ab(t_pushSwap piles)
{
	int		i;
	long	tmp;

	i = 0;
	while ((piles.a)[i] == EMPTY && i + 1 < piles.size)
		i++;
	tmp = (piles.a)[i];
	while (++i < piles.size)
		(piles.a)[i - 1] = (piles.a)[i];
	if (i - 1 < piles.size)
		(piles.a)[i - 1] = tmp;
	i = 0;
	while ((piles.b)[i] == EMPTY && i + 1 < piles.size)
		i++;
	tmp = (piles.b)[i];
	while (++i < piles.size)
		(piles.b)[i - 1] = (piles.b)[i];
	if (i - 1 < piles.size)
		(piles.b)[i - 1] = tmp;
	print_piles(piles);
	return (ft_printf("   rr\n"), 1);
}

#endif