/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:39:04 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/04 15:43:51 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_sort_a_to_b(t_pushSwap piles, long *pile, t_inPile a)
{
	if (!ssmallest_on_top_a(piles, pile, a))
	{
		push_b(piles);
		pile++;
		a.smallest = find_smallest(piles, piles.a);
		smallest_on_top_a(piles, pile, a);
		push_b(piles);
		swap_b(piles);
	}
	else if (!pile_sorted(piles, pile))
		push_b(piles);
}

void	algo_push_b_to_a(t_pushSwap piles, t_inPile b)
{
	while (1)
	{
		b.elems = pile_size(piles, piles.b);
		if (!(b.elems > 0))
			break ;
		push_a(piles);
	}
}

static int	algorithm(t_pushSwap piles)
{
	t_inPile	a;
	t_inPile	b;
	int			i;

	while (1)
	{
		a.smallest = find_smallest(piles, piles.a);
		i = 0;
		if (a.smallest == EMPTY || pile_sorted(piles, piles.a))
			break ;
		while ((piles.a)[i] == EMPTY)
			i++;
		if (i >= piles.size - 1)
			break ;
		a.elems = pile_size(piles, piles.a);
		if (a.elems == 2)
			algo_2_elements_a(piles);
		else if (a.elems == 3)
			algo_3_elements_a(piles);
		if (a.elems >= 0 && 3 >= a.elems)
			break ;
		algo_sort_a_to_b(piles, piles.a + i, a);
	}
	return (algo_push_b_to_a(piles, b), 1);
}

static int	push_swap(char **args, int size)
{
	t_pushSwap	piles;

	piles = get_piles(args, size);
	if (!(piles.a) || !(piles.b))
		return (0);
	algorithm(piles);
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
