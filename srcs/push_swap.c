/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:39:04 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/18 14:59:03 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_operations(t_pushSwap piles)
{
	t_operation	*current;

	current = piles.operations;
	while (current)
	{
		if (current->operation == SA)
			ft_printf("sa\n");
		else if (current->operation == SB)
			ft_printf("sb\n");
		else if (current->operation == SS)
			ft_printf("ss\n");
		else if (current->operation == PA)
			ft_printf("pa\n");
		else if (current->operation == PB)
			ft_printf("pb\n");
		else if (current->operation == RA)
			ft_printf("ra\n");
		else if (current->operation == RB)
			ft_printf("rb\n");
		else if (current->operation == RR)
			ft_printf("rr\n");
		else if (current->operation == RRA)
			ft_printf("rra\n");
		else if (current->operation == RRB)
			ft_printf("rrb\n");
		else if (current->operation == RRR)
			ft_printf("rrr\n");
		current = current->next;
	}
}

void	free_operations(t_pushSwap piles)
{
	t_operation	*current;
	t_operation	*tmp;

	tmp = piles.operations;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
}

t_operation *new_operation(t_pushSwap piles, int operation)
{
	t_operation	*current;

	current = piles.operations;
	if (!current)
	{
		free_operations(piles);
		free(piles.a);
		free(piles.b);
		ft_printf(ERR_ALLOC);
		exit(1);
	}
	while (current->next)
		current = current->next;
	current->next = malloc(sizeof(t_operation));
	if (!(current->next))
	{
		free_operations(piles);
		free(piles.a);
		free(piles.b);
		ft_printf(ERR_ALLOC);
		exit(1);
	}
	current->next->operation = operation;
	current->next->next = NULL;
	return (current->next);
}

static int	push_swap(char **args, int size)
{
	t_pushSwap	piles;

	piles = get_piles(args, size);
	if (!(piles.a) || !(piles.b))
		return (0);
	// piles.operations = malloc(sizeof(t_operation));
	// if (!(piles.operations))
	// {
	// 	ft_printf(ERR_ALLOC);
	// 	return (free(piles.a), free(piles.b), 0);
	// }
	// piles.operations->operation = NONE;
	// piles.operations->next = NULL;
	algorithm(piles);
	// ft_printf("|LISTE|\n");
	// print_operations(piles);
	// free_operations(piles);
	return (free(piles.a), free(piles.b), 1);
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