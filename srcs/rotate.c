/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:53:53 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/10 19:18:55 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#ifndef VISUALISATION

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
		((piles.a) + i - 1)->nbr = tmp.nbr;
	return (ft_printf("ra\n"), 1);
}

int	rotate_b(t_pushSwap piles)
{
	int		i;
	long	tmp;

	i = 0;
	while (((piles.b) + i)->nbr == EMPTY && i + 1 < piles.size)
		i++;
	tmp = ((piles.b) + i)->nbr;
	if (i + 1 >= piles.size)
		return (0);
	while (++i < piles.size)
		((piles.b) + i - 1)->nbr = ((piles.b) + i)->nbr;
	if (i - 1 < piles.size)
		((piles.b) + i - 1)->nbr = tmp;
	return (ft_printf("rb\n"), 1);
}

int	rotate_ab(t_pushSwap piles)
{
	int		i;
	long	tmp;

	i = 0;
	while (((piles.a) + i)->nbr == EMPTY && i + 1 < piles.size)
		i++;
	tmp = ((piles.a) + i)->nbr;
	while (++i < piles.size)
		((piles.a) + i - 1)->nbr = ((piles.a) + i)->nbr;
	if (i - 1 < piles.size)
		((piles.a) + i - 1)->nbr = tmp;
	i = 0;
	while (((piles.b) + i)->nbr == EMPTY && i + 1 < piles.size)
		i++;
	tmp = ((piles.b) + i)->nbr;
	while (++i < piles.size)
		((piles.b) + i - 1)->nbr = ((piles.b) + i)->nbr;
	if (i - 1 < piles.size)
		((piles.b) + i - 1)->nbr = tmp;
	return (ft_printf("rr\n"), 1);
}

#endif

#ifdef VISUALISATION

int	rotate_a(t_pushSwap piles)
{
	int		i;
	long	tmp;

	i = 0;
	while (((piles.a) + i)->nbr == EMPTY && i + 1 < piles.size)
		i++;
	tmp = ((piles.a) + i)->nbr;
	if (i + 1 >= piles.size)
		return (0);
	while (++i < piles.size)
		((piles.a) + i - 1)->nbr = ((piles.a) + i)->nbr;
	if (i - 1 < piles.size)
		((piles.a) + i - 1)->nbr = tmp;
	print_piles(piles);
	return (ft_printf("   ra\n"), 1);
}

int	rotate_b(t_pushSwap piles)
{
	int		i;
	long	tmp;

	i = 0;
	while (((piles.b) + i)->nbr == EMPTY && i + 1 < piles.size)
		i++;
	tmp = ((piles.b) + i)->nbr;
	if (i + 1 >= piles.size)
		return (0);
	while (++i < piles.size)
		((piles.b) + i - 1)->nbr = ((piles.b) + i)->nbr;
	if (i - 1 < piles.size)
		((piles.b) + i - 1)->nbr = tmp;
	print_piles(piles);
	return (ft_printf("   rb\n"), 1);
}

int	rotate_ab(t_pushSwap piles)
{
	int		i;
	long	tmp;

	i = 0;
	while (((piles.a) + i)->nbr == EMPTY && i + 1 < piles.size)
		i++;
	tmp = ((piles.a) + i)->nbr;
	while (++i < piles.size)
		((piles.a) + i - 1)->nbr = ((piles.a) + i)->nbr;
	if (i - 1 < piles.size)
		((piles.a) + i - 1)->nbr = tmp;
	i = 0;
	while (((piles.b) + i)->nbr == EMPTY && i + 1 < piles.size)
		i++;
	tmp = ((piles.b) + i)->nbr;
	while (++i < piles.size)
		((piles.b) + i - 1)->nbr = ((piles.b) + i)->nbr;
	if (i - 1 < piles.size)
		((piles.b) + i - 1)->nbr = tmp;
	print_piles(piles);
	return (ft_printf("   rr\n"), 1);
}

#endif