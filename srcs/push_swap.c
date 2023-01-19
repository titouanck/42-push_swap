/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:39:04 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/19 23:34:07 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_swap(char **args, int size)
{
	t_pushSwap	piles;

	piles = get_piles(args, size);
	if (!(piles.a) || !(piles.b))
		return (0);
	piles = duplicate_piles(piles);
	piles.operations = malloc(sizeof(t_operation));
	if (!(piles.operations))
	{
		ft_putstr_fd(ERR_ALLOC, 2);
		return (free(piles.a), free(piles.b), 0);
	}
	piles.operations->operation = NONE;
	piles.operations->next = NULL;
	if (!pile_sorted(piles, piles.a))
		algorithm(piles);
	optimise_operations(piles);
	print_operations(piles);
	free_operations(piles);
	return (free(piles.original_a), free(piles.original_b), 1);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (1);
	else if (!push_swap(argv + 1, argc - 1))
		return (1);
	return (0);
}
