/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:32:07 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/02 18:13:23 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_pushSwap piles)
{
	int	i;
	int	j;

	i = 0;
	while ((piles.b)[i] == EMPTY && i < piles.size)
		i++;
	if (i >= piles.size)
		return ;
	j = 0;
	while ((piles.a)[j + 1] == EMPTY && j < piles.size)
		j++;
	if (j >= piles.size)
		return ;
	ft_swap(&((piles.b)[i]), &((piles.a)[j]));
	ft_printf("pa\n");
}

void	push_b(t_pushSwap piles)
{
	int	i;
	int	j;

	i = 0;
	while ((piles.a)[i] == EMPTY && i < piles.size)
		i++;
	if (i >= piles.size)
		return ;
	j = 0;
	while ((piles.b)[j + 1] == EMPTY && j < piles.size)
		j++;
	if (j >= piles.size)
		return ;
	ft_swap(&((piles.a)[i]), &((piles.b)[j]));
	ft_printf("pa\n");
}
