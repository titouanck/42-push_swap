/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_piles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:05:50 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/18 17:49:34 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_piles(t_pushSwap piles)
{
	int	i;

	i = 0;
	ft_printf("---===---\n");
	while (i < piles.size && ((piles.a) + i)->nbr == EMPTY
		&& ((piles.b) + i)->nbr == EMPTY)
		i++;
	while (i < piles.size)
	{
		if (((piles.a) + i)->nbr != EMPTY)
			ft_printf("%d", ((piles.a) + i)->index);
		else
			ft_printf(" ");
		ft_printf("\t");
		if (((piles.b) + i)->nbr != EMPTY)
			ft_printf("%d", ((piles.b) + i)->index);
		else
			ft_printf(" ");
		ft_printf("\n");
		i++;
	}
	ft_printf("-\t-\n");
	ft_printf("a\tb\n");
	ft_printf("---===---\n");
}
