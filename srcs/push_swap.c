/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:39:04 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/18 16:53:55 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_operations(t_pushSwap piles)
{
	int			nbr;
	t_operation	*current;

	nbr = 0;
	current = piles.operations;
	while (current)
	{
		if (current->operation != NONE)
			nbr++;
		current = current->next;
	}
	return (nbr);
}

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

	current = piles.operations;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
}

static void	actions_err_alloc_operation(t_pushSwap piles)
{
	free_operations(piles);
	free(piles.a);
	free(piles.b);
	free(piles.original_a);
	free(piles.original_b);
	ft_printf(ERR_ALLOC);
	exit(1);
}

t_operation *new_operation(t_pushSwap piles, int operation)
{
	t_operation	*current;

	current = piles.operations;
	if (!current)
		actions_err_alloc_operation(piles);
	while (current->next)
		current = current->next;
	current->next = malloc(sizeof(t_operation));
	if (!(current->next))
		actions_err_alloc_operation(piles);
	current->next->operation = operation;
	current->next->next = NULL;
	return (current->next);
}

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
