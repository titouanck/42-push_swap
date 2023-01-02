/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:31:28 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/02 18:14:54 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_pushSwap piles)
{
	int	i;

	i = 0;
	while ((piles.a)[i] == EMPTY && i + 1 < piles.size)
		i++;
	if (i + 1 < piles.size)
		ft_swap(&((piles.a)[i]), &((piles.a)[i + 1]));
	ft_printf("sa\n");
}

void	swap_b(t_pushSwap piles)
{
	int	i;

	i = 0;
	while ((piles.b)[i] == EMPTY && i + 1 < piles.size)
		i++;
	if (i + 1 < piles.size)
		ft_swap(&((piles.b)[i]), &((piles.b)[i + 1]));
	ft_printf("sb\n");
}

void	swap_ab(t_pushSwap piles)
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
	ft_printf("ss\n");
}
