/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:43:00 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/02 18:14:42 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	*get_numbers_a(char **args, int sz)
{
	long	*tab;
	int		i;
	int		j;

	tab = malloc(sizeof(long) * (sz * 2));
	if (!tab)
		return (ft_printf(ERR_ALLOC), NULL);
	i = 0;
	while (i < sz)
		tab[i++] = EMPTY;
	while (i < sz * 2)
	{
		j = 0;
		while (args[i - sz][j])
		{
			if (j == 0 && (args[i - sz][j] == '+' || args[i - sz][j] == '-'))
				j = j;
			else if (!ft_isdigit(args[i - sz][j]))
				return (ft_printf(ERR_WRONGTYPEARGS), free(tab), NULL);
			j++;
		}
		tab[i] = ft_atoi(args[i - sz]);
		i++;
	}
	return (tab);
}

static long	*get_numbers_b(int size)
{
	long	*tab;
	int		i;

	tab = malloc(sizeof(long) * (size * 2));
	if (!tab)
		return (ft_printf(ERR_ALLOC), NULL);
	i = 0;
	while (i < size * 2)
	{
		tab[i] = EMPTY;
		i++;
	}
	return (tab);
}

static int	check_duplicate(long *tab, int size)
{
	int	i;
	int	j;

	i = size;
	while (i < size * 2)
	{
		j = i + 1;
		while (j < size * 2)
		{
			if (tab[i] == tab[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

t_pushSwap	get_piles(char **args, int size)
{
	t_pushSwap	piles;

	piles.a = 0;
	piles.b = 0;
	piles.a = get_numbers_a(args, size);
	if (!piles.a)
		return (piles);
	if (!check_duplicate(piles.a, size))
		return (ft_printf(ERR_DUPLICATEARGS), free(piles.a), piles);
	piles.b = get_numbers_b(size);
	if (!piles.b)
		return (free(piles.a), piles);
	piles.size = size * 2;
	return (piles);
}
