/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:23:21 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/05 17:43:14 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#ifdef MANUAL

int	manual_push_swap(char **args, int size)
{
	char		str[100];
	int			readed;
	int			count;
	t_pushSwap	piles;

	count = 0;
	piles = get_piles(args, size);
	if (!(piles.a) || !(piles.b))
		return (0);
	print_piles(piles);
	while (1)
	{
		if (pile_sorted(piles, piles.a) && pile_size(piles, piles.b) == 0)
		{
			if (count == 0)
				ft_printf("La pile est triée.\n");
			else if (count == 1)
				ft_printf("La pile a été triée en %d coup.\n", count);
			else
				ft_printf("La pile a été triée en %d coups.\n", count);
			break ;
		}
		ft_printf("\n$> ");
		readed = read(0, str, 99);
		if (readed == 2)
			str[2] = '\0';
		if (readed <= 0)
			break ;
		else if (str[0] == 's' && str[1] == 'a')
			swap_a(piles);
		else if (str[0] == 's' && str[1] == 'b')
			swap_b(piles);
		else if (str[0] == 's' && str[1] == 's')
			swap_ab(piles);
		else if (str[0] == 'p' && str[1] == 'a')
			push_a(piles);
		else if (str[0] == 'p' && str[1] == 'b')
			push_b(piles);
		else if (str[0] == 'r' && str[1] == 'a')
			rotate_a(piles);
		else if (str[0] == 'r' && str[1] == 'b')
			rotate_b(piles);
		else if (str[0] == 'r' && str[1] == 'r' && str[2] == '\0')
			rotate_ab(piles);
		else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'a')
			rev_rotate_a(piles);
		else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'b')
			rev_rotate_b(piles);
		else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'r')
			rev_rotate_ab(piles);
		else if (ft_strncmp(str, "reset\n", ft_strlen("reset\n") + 1) == 0)
		{
			ft_printf("Soon..\n");
			count--;
		}
		else
		{
			ft_printf("Not a valid operation.\n");
			count--;			
		}
		count++;
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