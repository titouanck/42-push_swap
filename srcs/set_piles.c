/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_piles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 02:26:01 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/19 02:48:28 by tchevrie         ###   ########.fr       */
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
		return (ft_putstr_fd(ERR_ALLOC, 2), piles);
	piles.original_b = malloc(sizeof(t_elem) * piles.size);
	if (!(piles.original_b))
	{
		free(piles.original_a);
		piles.original_a = NULL;
		return (ft_putstr_fd(ERR_ALLOC, 2), piles);
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
