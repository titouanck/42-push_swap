/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:56:16 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/03 04:21:13 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(long *a, long *b)
{
	long	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	print_piles(t_pushSwap piles)
{
	int	i;

	i = 0;
	ft_printf("---===---\n");
	while (i < piles.size && (piles.a)[i] == EMPTY && (piles.b)[i] == EMPTY)
			i++;
	while (i < piles.size)
	{
		if ((piles.a)[i] != EMPTY)
			ft_printf("%d", (piles.a)[i]);
		else
			ft_printf(" ");
		ft_printf("\t");
		if ((piles.b)[i] != EMPTY)
			ft_printf("%d", (piles.b)[i]);
		else
			ft_printf(" ");
		ft_printf("\n");
		i++;
	}
	ft_printf("-\t-\n");
	ft_printf("a\tb\n");
	ft_printf("---===---\n");
}

long	find_smallest(t_pushSwap piles, long *pile)
{
	long	smallest;
	int		i;

	smallest = EMPTY;
	i = 0;
	while (i < piles.size)
	{
		if (pile[i] < smallest && pile[i] != EMPTY)
			smallest = pile[i];
		i++;
	}
	return (smallest);
}

long	find_biggest(t_pushSwap piles, long *pile)
{
	long	biggest;
	int		i;

	biggest = -EMPTY;
	i = 0;
	while (i < piles.size)
	{
		if (pile[i] > biggest && pile[i] != EMPTY)
			biggest = pile[i];
		i++;
	}
	return (biggest);
}
