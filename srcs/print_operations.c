/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:51:40 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/18 17:52:00 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_operations_bis(t_operation *current)
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
}

void	print_operations(t_pushSwap piles)
{
	t_operation	*current;

	current = piles.operations;
	while (current)
	{
		print_operations_bis(current);
		current = current->next;
	}
}