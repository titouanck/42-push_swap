/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:45:03 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/18 17:52:21 by tchevrie         ###   ########.fr       */
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

t_operation	*new_operation(t_pushSwap piles, int operation)
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
