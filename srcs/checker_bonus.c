/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 02:15:52 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/20 01:21:10 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_operations_bis(t_pushSwap piles, char *line)
{
	if (ft_strcmp("sa\n", line) == 0)
		swap_a(piles);
	else if (ft_strcmp("sb\n", line) == 0)
		swap_b(piles);
	else if (ft_strcmp("ss\n", line) == 0)
		swap_ab(piles);
	else if (ft_strcmp("pa\n", line) == 0)
		push_a(piles);
	else if (ft_strcmp("pb\n", line) == 0)
		push_b(piles);
	else if (ft_strcmp("ra\n", line) == 0)
		rotate_a(piles);
	else if (ft_strcmp("rb\n", line) == 0)
		rotate_b(piles);
	else if (ft_strcmp("rr\n", line) == 0)
		rotate_ab(piles);
	else if (ft_strcmp("rra\n", line) == 0)
		rev_rotate_a(piles);
	else if (ft_strcmp("rrb\n", line) == 0)
		rev_rotate_b(piles);
	else if (ft_strcmp("rrr\n", line) == 0)
		rev_rotate_ab(piles);
	else
		return (0);
	return (1);
}

static int	get_operations(t_pushSwap piles)
{
	int		success;
	char	*line;

	success = 1;
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (ft_strlen(line) > 4)
			success = 0;
		else if (!get_operations_bis(piles, line))
			success = 0;
		free(line);
	}
	return (success);
}

static int	checker_push_swap(char **args, int size)
{
	t_pushSwap	piles;

	piles = get_piles(args, size);
	if (!(piles.a) || !(piles.b))
		return (0);
	piles = duplicate_piles(piles);
	piles.operations = malloc(sizeof(t_operation));
	if (!(piles.operations))
		return (ft_putstr_fd(ERR_ALLOC, 2), free(piles.a), free(piles.b), 0);
	piles.operations->operation = NONE;
	piles.operations->next = NULL;
	if (!get_operations(piles))
		ft_putstr_fd("Error\n", 2);
	else if (!pile_sorted(piles, piles.a) || pile_size(piles, piles.b) > 0)
	{
		ft_printf("KO\n");
		free_operations(piles);
		return (free(piles.original_a), free(piles.original_b), 0);
	}
	else
		ft_printf("OK\n");
	free_operations(piles);
	return (free(piles.original_a), free(piles.original_b), 1);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (1);
	else if (!checker_push_swap(argv + 1, argc - 1))
		return (1);
	return (0);
}
