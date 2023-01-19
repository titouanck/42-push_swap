/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimise_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 23:33:46 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/19 23:46:22 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	optimise_operations_ra(t_operation *current)
{
	t_operation	*check;

	check = current;
	while (check && check->operation != RB)
	{
		if (check->operation == PA || check->operation == PB
			|| check->operation == SB || check->operation == SS)
			break ;
		check = check->next;
	}
	if (check && check->operation == RB)
	{
		current->operation = RR;
		check->operation = NONE;
	}
}

static void	optimise_operations_rb(t_operation *current)
{
	t_operation	*check;

	check = current;
	while (check && check->operation != RA)
	{
		if (check->operation == PB || check->operation == PA
			|| check->operation == SA || check->operation == SS)
			break ;
		check = check->next;
	}
	if (check && check->operation == RA)
	{
		current->operation = RR;
		check->operation = NONE;
	}
}

static void	optimise_operations_rra(t_operation *current)
{
	t_operation	*check;

	check = current;
	while (check && check->operation != RRB)
	{
		if (check->operation == PA || check->operation == PB
			|| check->operation == SB || check->operation == SS)
			break ;
		check = check->next;
	}
	if (check && check->operation == RRB)
	{
		current->operation = RRR;
		check->operation = NONE;
	}
}

static void	optimise_operations_rrb(t_operation *current)
{
	t_operation	*check;

	check = current;
	while (check && check->operation != RRA)
	{
		if (check->operation == PB || check->operation == PA
			|| check->operation == SA || check->operation == SS)
			break ;
		check = check->next;
	}
	if (check && check->operation == RRA)
	{
		current->operation = RRR;
		check->operation = NONE;
	}
}

void	optimise_operations(t_pushSwap piles)
{
	t_operation	*current;

	current = piles.operations;
	while (current)
	{
		if (current->operation == RA)
			optimise_operations_ra(current);
		else if (current->operation == RB)
			optimise_operations_rb(current);
		else if (current->operation == RRA)
			optimise_operations_rra(current);
		else if (current->operation == RRB)
			optimise_operations_rrb(current);
		current = current->next;
	}
}
