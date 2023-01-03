/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:39:04 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/03 04:21:59 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	algorithm(t_pushSwap piles)
{
	t_inPile	a;
	t_inPile	b;
	int			i;

	while (1)
	{
		a.smallest = find_smallest(piles, piles.a);
		if (a.smallest == EMPTY)
			break ;
		i = 0;
		while ((piles.a)[i] == EMPTY)
			i++;
		while ((piles.a)[i] != a.smallest)
			rotate_a(piles);
		push_b(piles);
	}
	while (1)
		if (!push_a(piles))
			break ;
}

static int	push_swap(char **args, int size)
{
	t_pushSwap	piles;

	piles = get_piles(args, size);
	if (!(piles.a) || !(piles.b))
		return (0);
	algorithm(piles);
	print_piles(piles);
	return (free(piles.a), free(piles.b), 1);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (1);
	else if (!push_swap(argv + 1, argc - 1))
		return (1);
	return (0);
}
