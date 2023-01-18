/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:39:04 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/18 17:50:02 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset_piles(t_pushSwap piles)
{
	int			i;
	t_operation	*current;
	t_operation	*tmp;

	i = 0;
	while (i < piles.size)
	{
		(piles.a)[i] = (piles.original_a)[i];
		(piles.b)[i] = (piles.original_b)[i];
		i++;
	}
	current = piles.operations;
	if (!current)
		return ;
	current = current->next;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	piles.operations->next = NULL;
}

t_pushSwap	duplicate_piles(t_pushSwap piles)
{
	int	i;

	piles.original_a = malloc(sizeof(t_elem) * piles.size);
	if (!(piles.original_a))
		return (ft_printf(ERR_ALLOC), piles);
	piles.original_b = malloc(sizeof(t_elem) * piles.size);
	if (!(piles.original_b))
	{
		free(piles.original_a);
		piles.original_a = NULL;
		return (ft_printf(ERR_ALLOC), piles);
	}
	i = 0;
	while (i < piles.size)
	{
		(piles.original_a)[i] = (piles.a)[i];
		(piles.original_b)[i] = (piles.b)[i];
		i++;
	}
	return (piles);
}

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
		ft_printf(ERR_ALLOC);
		return (free(piles.a), free(piles.b), 0);
	}
	piles.operations->operation = NONE;
	piles.operations->next = NULL;
	algorithm(piles);
	print_operations(piles);
	free_operations(piles);
	return (free(piles.original_a), free(piles.original_b), 1);
}

#ifndef MANUAL

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (1);
	else if (!push_swap(argv + 1, argc - 1))
		return (1);
	return (0);
}

#endif
