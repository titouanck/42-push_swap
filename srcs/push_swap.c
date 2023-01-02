/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:39:04 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/02 18:12:32 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_swap(char **args, int size)
{
	t_pushSwap	piles;

	piles = get_piles(args, size);
	if (!(piles.a) || !(piles.b))
		return (0);
	print_piles(piles);
	push_b(piles);
	print_piles(piles);
	push_b(piles);
	print_piles(piles);
	rev_rotate_ab(piles);
	print_piles(piles);
	rev_rotate_ab(piles);
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
