/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:58:35 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/08 16:28:24 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#ifndef VISUALISATION

int	rev_rotate_a(t_pushSwap piles)
{
	int		i;
	long	tmp;

	i = piles.size - 1;
	tmp = (piles.a)[i];
	if (!(i - 1 >= 0 && (piles.a)[i - 1] != EMPTY))
		return (0);
	while (--i >= 0 && (piles.a)[i] != EMPTY)
		(piles.a)[i + 1] = (piles.a)[i];
	if (i + 1 >= 0)
		(piles.a)[i + 1] = tmp;
	return(action_lstaddback(piles, 9), 1);
}

int	rev_rotate_b(t_pushSwap piles)
{
	int		i;
	long	tmp;

	i = piles.size - 1;
	tmp = (piles.b)[i];
	if (!(i - 1 >= 0 && (piles.b)[i - 1] != EMPTY))
		return (0);
	while (--i >= 0 && (piles.b)[i] != EMPTY)
		(piles.b)[i + 1] = (piles.b)[i];
	if (i + 1 >= 0)
		(piles.b)[i + 1] = tmp;
	return(action_lstaddback(piles, 10), 1);
}

int	rev_rotate_ab(t_pushSwap piles)
{
	int		i;
	long	tmp;

	i = piles.size - 1;
	tmp = (piles.a)[i];
	while (--i >= 0 && (piles.a)[i] != EMPTY)
		(piles.a)[i + 1] = (piles.a)[i];
	if (i + 1 >= 0)
		(piles.a)[i + 1] = tmp;
	i = piles.size - 1;
	tmp = (piles.b)[i];
	while (--i >= 0 && (piles.b)[i] != EMPTY)
		(piles.b)[i + 1] = (piles.b)[i];
	if (i + 1 >= 0)
		(piles.b)[i + 1] = tmp;
	return(action_lstaddback(piles, 11), 1);
}

#endif

#ifdef VISUALISATION

int	rev_rotate_a(t_pushSwap piles)
{
	int		i;
	long	tmp;

	i = piles.size - 1;
	tmp = (piles.a)[i];
	if (!(i - 1 >= 0 && (piles.a)[i - 1] != EMPTY))
		return (0);
	while (--i >= 0 && (piles.a)[i] != EMPTY)
		(piles.a)[i + 1] = (piles.a)[i];
	if (i + 1 >= 0)
		(piles.a)[i + 1] = tmp;
	print_piles(piles);
	return(ft_printf("   rra\n"), 1);
}

int	rev_rotate_b(t_pushSwap piles)
{
	int		i;
	long	tmp;

	i = piles.size - 1;
	tmp = (piles.b)[i];
	if (!(i - 1 >= 0 && (piles.b)[i - 1] != EMPTY))
		return (0);
	while (--i >= 0 && (piles.b)[i] != EMPTY)
		(piles.b)[i + 1] = (piles.b)[i];
	if (i + 1 >= 0)
		(piles.b)[i + 1] = tmp;
	print_piles(piles);
	return(ft_printf("   rrb\n"), 1);
}

int	rev_rotate_ab(t_pushSwap piles)
{
	int		i;
	long	tmp;

	i = piles.size - 1;
	tmp = (piles.a)[i];
	while (--i >= 0 && (piles.a)[i] != EMPTY)
		(piles.a)[i + 1] = (piles.a)[i];
	if (i + 1 >= 0)
		(piles.a)[i + 1] = tmp;
	i = piles.size - 1;
	tmp = (piles.b)[i];
	while (--i >= 0 && (piles.b)[i] != EMPTY)
		(piles.b)[i + 1] = (piles.b)[i];
	if (i + 1 >= 0)
		(piles.b)[i + 1] = tmp;
	print_piles(piles);
	return(ft_printf("   rrr\n"), 1);
}

#endif
