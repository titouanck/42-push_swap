/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:23:21 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/04 19:35:19 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#ifdef MANUAL

int	manual_push_swap(int **args, int size)
{
	char		str[3];
	int			readed;
	t_pushSwap	piles;

	piles = get_piles(args, size);
	if (!(piles.a) || !(piles.b))
		return (0);
	while (1)
	{
		readed = read(0, &str, 2);
		if (readed == 2)
			str[2] = '\0';
		else if (readed == 0)
			break ;
		if (str[0] == 's' && str[1] == 'a')
			swap_a(piles);
		else if (str[0] == 's' && str[1] == 'b')
			swap_b(piles);
		else if (str[0] == 's' && str[1] == 's')
			swap_ab(piles);
		else if (str[0] == 'p' && str[1] == 'a')
			push_a(piles);
		else if (str[0] == 'p' && str[1] == 'b')
			push_b(piles);
		// ETC
		else
			ft_printf("Operations:\n \
			sa,\tsb,\tss,\n \
			pa,\tpb,\t\n \
			ra,\trb,\trr,\n \
			rra,\trrb,\trrr\n");
	}
	return (free(piles.a), free(piles.b), 1);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (1);
	else if (!manual_push_swap(argv + 1, argc - 1))
		return (1);
	return (0);
}

#endif