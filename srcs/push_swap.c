/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:39:04 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/05 16:09:04 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	smallest_remaining(t_pushSwap piles, long *pile, long *tab)
{
	long	smallest;
	int		i;
	int		element;
	int		found;

	smallest = EMPTY;
	i = 0;
	while (i < piles.size)
	{
		if (pile[i] < smallest && pile[i] != EMPTY)
		{
			element = 0;
			found = 0;
			while (tab[i] != EMPTY && element < 10)
				if (pile[i] == tab[element++])
					found = 1;
			if (!found)
				smallest = pile[i];			
		}
		i++;
	}
	return (smallest);
}

long	*group_of_ten(t_pushSwap piles, long *pile, int elems)
{
	int		i;
	long	*tab;
	int		element;

	i = 0;
	while (i < piles.size && pile[i] == EMPTY)
		i++;
	if (i >= piles.size)
		return (NULL);
	tab = malloc(sizeof(long) * 10);
	if (!tab)
		return (NULL);
	element = 0;
	while (element < 10 && element < elems)
	{
		tab[element] = smallest_remaining(piles, pile + i, tab);
		element++;
	}
	while (element < 10)
		tab[element++] = EMPTY;
	return (tab);
}

void	print_tab(long *tab)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (tab[i] != EMPTY)
			printf("tab[%d] = %ld\n", i, tab[i]);
		i++;
	}
}

int	tab_elements(long *tab)
{
	int	i;
	int	elems;

	i = 0;
	while (i < 10)
	{
		if (tab[i] != EMPTY)
			elems++;
		i++;
	}
	return (i);
}

long	find_nearest_tab_elem_a(t_pushSwap piles, long *tab)
{
	int	i;
	int	j;

	i = 0;
	while ((piles.a)[i] == EMPTY)
		i++;
	while (i < piles.size)
	{
		j = 0;
		while (j < 10)
		{
			if (tab[j] != EMPTY && (piles.a)[i] == tab[j])
				return (tab[j]);
			else if (tab[j] != EMPTY && (piles.a)[piles.size - 1 - i] == tab[j])
				return (tab[j]);
			j++;
		}
		i++;
	}
	return (EMPTY);
}

// void	algorithm_exsator(t_pushSwap piles)
// {
// 	t_inPile	a;
// 	long		*tab;

// 	while (1)
// 	{
// 		define_properties_a(piles, &a);
// 		if (a.elems < 2 || pile_sorted(piles, piles.a))
// 			break ;
// 		tab = group_of_ten(piles, piles.a, a.elems);
// 		if (!tab)
// 			break ;
// 		while (tab_elements(tab) > 0)
// 		{
			
// 		}
		
// 	}
// }

static int	push_swap(char **args, int size)
{
	t_pushSwap	piles;

	piles = get_piles(args, size);
	if (!(piles.a) || !(piles.b))
		return (0);
	algorithm_djimo(piles);
	return (free(piles.a), free(piles.b), 1);
}

#ifndef MANUAL

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (1);
	else if (!push_swap(argv + 1, argc - 1))
		return (1);
	return (0);
}

#endif