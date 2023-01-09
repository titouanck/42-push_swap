/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:13:47 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/08 16:31:28 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	action_lstaddback(t_pushSwap piles, int action)
{
	t_actions *current;

	if (!(piles.actions))
	{
		piles.actions = malloc(sizeof(t_actions));
		if (!(piles.actions))
			return (ft_printf(ERR_ALLOC), 0);
		current = piles.actions;
	}
	else
	{
		current = piles.actions;
		while (current->next)
			current = current->next;
		current->next = malloc(sizeof(t_actions));
		current = current->next;
	}
	current->action = action;
	return (1);
}

void	free_actions(t_pushSwap piles)
{
	t_actions	*current;
	t_actions	*tmp;

	current = piles.actions;
	while (current && current->next)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	free(current);
}

void	print_actions(t_pushSwap piles)
{
	t_actions	*current;

	current = piles.actions;
	while (current)
	{
		if (current->action == 1)
			ft_printf("sa\n");
		if (current->action == 2)
			ft_printf("sb\n");
		if (current->action == 3)
			ft_printf("ss\n");
		if (current->action == 4)
			ft_printf("pa\n");
		if (current->action == 5)
			ft_printf("pb\n");
		if (current->action == 6)
			ft_printf("ra\n");
		if (current->action == 7)
			ft_printf("rb\n");
		if (current->action == 8)
			ft_printf("rr\n");
		if (current->action == 9)
			ft_printf("rra\n");
		if (current->action == 10)
			ft_printf("rrb\n");
		if (current->action == 11)
			ft_printf("rrr\n");
		current = current->next;
	}
}