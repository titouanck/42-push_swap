/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:53:53 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/02 18:13:16 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_pushSwap piles)
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
	ft_printf("ra\n");
}

void	rotate_b(t_pushSwap piles)
{
	int		i;
	long	tmp;

	i = 0;
	while ((piles.b)[i] == EMPTY && i + 1 < piles.size)
		i++;
	tmp = (piles.b)[i];
	while (++i < piles.size)
		(piles.b)[i - 1] = (piles.b)[i];
	if (i - 1 < piles.size)
		(piles.b)[i - 1] = tmp;
	ft_printf("ra\n");
}

void	rotate_ab(t_pushSwap piles)
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
	ft_printf("rr\n");
}
