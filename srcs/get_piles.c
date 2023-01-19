/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:43:00 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/19 01:53:00 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_elem	*get_numbers_a(char **args, int sz)
{
	t_elem	*tab;
	int		i;
	int		j;

	tab = malloc(sizeof(t_elem) * sz);
	if (!tab)
		return (ft_printf(ERR_ALLOC), NULL);
	i = 0;
	while (i < sz)
	{
		j = 0;
		while (args[i][j])
		{
			if (!(j == 0 && (args[i][j] == '+' || args[i][j] == '-'))
				&& (!ft_isdigit(args[i][j])))
				return (ft_printf(ERR_WRONGTYPEARGS), free(tab), NULL);
			j++;
		}
		(tab + i)->nbr = ft_atoi_long(args[i]);
		(tab + i)->index = EMPTY;
		if ((tab + i)->nbr == EMPTY)
			return (ft_printf(ERR_BIGGERTHANINT), free(tab), NULL);
		i++;
	}
	return (tab);
}

static t_elem	*get_numbers_b(int size)
{
	t_elem	*tab;
	int		i;

	tab = malloc(sizeof(t_elem) * size);
	if (!tab)
		return (ft_printf(ERR_ALLOC), NULL);
	i = 0;
	while (i < size)
	{
		(tab + i)->nbr = EMPTY;
		(tab + i)->index = EMPTY;
		i++;
	}
	return (tab);
}

static void	define_index(t_pushSwap piles)
{
	int		j;
	int		i;
	long	last_nbr;
	long	last_index;

	j = 0;
	while (j < piles.size)
	{
		last_index = EMPTY;
		last_nbr = EMPTY;
		i = 0;
		while (i < piles.size)
		{
			if (((piles.a) + i)->index == EMPTY
				&& ((piles.a) + i)->nbr < last_nbr)
			{
				last_nbr = ((piles.a) + i)->nbr;
				last_index = i;
			}
			i++;
		}
		((piles.a) + last_index)->index = j;
		j++;
	}
}

static int	check_duplicate(t_elem *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if ((tab + i)->nbr == (tab + j)->nbr)
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

	piles.size = size;
	piles.a = get_numbers_a(args, size);
	if (!piles.a)
		return (piles);
	if (!check_duplicate(piles.a, size))
	{
		ft_printf(ERR_DUPLICATEARGS);
		free(piles.a);
		piles.a = NULL;
		return (piles);
	}
	define_index(piles);
	piles.b = get_numbers_b(size);
	if (!piles.b)
	{
		free(piles.a);
		piles.a = NULL;
		return (piles);
	}
	return (piles);
}
