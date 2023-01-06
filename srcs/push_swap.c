/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:39:04 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/06 04:59:57 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// long	smallest_remaining(t_pushSwap piles, long *pile, long *tab)
// {
// 	long	smallest;
// 	int		i;
// 	int		element;
// 	int		found;

// 	smallest = EMPTY;
// 	i = 0;
// 	while (i < piles.size)
// 	{
// 		if (pile[i] < smallest && pile[i] != EMPTY)
// 		{
// 			element = 0;
// 			found = 0;
// 			while (tab[i] != EMPTY && element < 10)
// 				if (pile[i] == tab[element++])
// 					found = 1;
// 			if (!found)
// 				smallest = pile[i];			
// 		}
// 		i++;
// 	}
// 	return (smallest);
// }

// long	*group_of_ten(t_pushSwap piles, long *pile, int elems)
// {
// 	int		i;
// 	long	*tab;
// 	int		element;

// 	i = 0;
// 	while (i < piles.size && pile[i] == EMPTY)
// 		i++;
// 	if (i >= piles.size)
// 		return (NULL);
// 	tab = malloc(sizeof(long) * 10);
// 	if (!tab)
// 		return (NULL);
// 	element = 0;
// 	while (element < 10 && element < elems)
// 	{
// 		tab[element] = smallest_remaining(piles, pile + i, tab);
// 		element++;
// 	}
// 	while (element < 10)
// 		tab[element++] = EMPTY;
// 	return (tab);
// }

// void	print_tab(long *tab)
// {
// 	int	i;

// 	i = 0;
// 	while (i < 10)
// 	{
// 		if (tab[i] != EMPTY)
// 			printf("tab[%d] = %ld\n", i, tab[i]);
// 		i++;
// 	}
// }

// int	tab_elements(long *tab)
// {
// 	int	i;
// 	int	elems;

// 	i = 0;
// 	while (i < 10)
// 	{
// 		if (tab[i] != EMPTY)
// 			elems++;
// 		i++;
// 	}
// 	return (i);
// }

// long	find_nearest_tab_elem_a(t_pushSwap piles, long *tab)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while ((piles.a)[i] == EMPTY)
// 		i++;
// 	while (i < piles.size)
// 	{
// 		j = 0;
// 		while (j < 10)
// 		{
// 			if (tab[j] != EMPTY && (piles.a)[i] == tab[j])
// 				return (tab[j]);
// 			else if (tab[j] != EMPTY && (piles.a)[piles.size - 1 - i] == tab[j])
// 				return (tab[j]);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (EMPTY);
// }

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

int	in_tab(long *tab, long elem, int tabsize)
{
	int	i;

	i = 0;
	while (i < tabsize)
	{
		if (tab[i] == elem)
			return (1);
		i++;
	}
	return (0);
}

long	find_tab_biggest(t_pushSwap piles, long *pile, long *tab, int size)
{
	long	biggest;
	int		i;

	biggest = -EMPTY;
	i = 0;
	while (i < piles.size)
	{
		if (pile[i] > biggest && pile[i] != EMPTY  && in_tab(tab, pile[i], size))
			biggest = pile[i];
		i++;
	}
	return (biggest);
}

void	algorithm_dewey(t_pushSwap piles)
{
	int			i;
	int			j;
	int			k;
	int			in_valid_order;
	long		last_nbr;
	long		*out;
	int			biggest;
	t_inPile	a;
	t_inPile	b;
	t_dewey		biggest;

	out = malloc(sizeof(long) * piles.elems);
	if (!out)
		return ;
	biggest.first_nbr = EMPTY;
	biggest.in_valid_order = 0;
	biggest.out = NULL;
	i = 0;
	while (i < piles.elems)
	{
		
		j = 0;
		define_properties_a(piles, &a);
		while ((piles.a)[j] == EMPTY)
			j++;
		k = 0;
		while (k++ < i)
			j++;
		k = 0;
		last_nbr = -EMPTY;
		in_valid_order = 0;
		while (k < piles.elems)
		{
			if ((piles.a)[j] > last_nbr)
			{
				in_valid_order++;
				last_nbr = (piles.a)[j];
				out[k] = EMPTY;
			}
			else
				out[k] = (piles.a)[j];
			j++;
			if (j >= piles.size)
				j = piles.size - a.elems;
			k++;
		}
		if (in_valid_order > biggest.in_valid_order)
		{
			biggest.in_valid_order = in_valid_order;
			biggest.first_nbr = i;
			if (biggest.out)
				free(biggest.out);
			biggest.out = out;
			out = malloc(sizeof(long) * piles.elems);
			if (!out)
			{
				free(biggest.out);
				return ;
			}
		}
		i++;
	}
	i = 0;
	while ((piles.a)[i] == EMPTY && i < piles.size)
		i++;
	while ((biggest.first_nbr)-- > 0)
		i++;
	place_element_on_top_a(piles, (piles.a)[i]);
	k = 0;
	while (k < piles.elems && !pile_sorted(piles, piles.a))
	{
		biggest = find_tab_biggest(piles, piles.a, biggest.out, piles.elems);
		place_element_on_top_a(piles, biggest);
		i = 0;
		while (i < piles.elems)
		{
			if ((biggest.out)[i] == biggest)
			{
				(biggest.out)[i] = EMPTY;
				break ;
			}
			i++;
		}
		push_b(piles);
		while (i < piles.elems)
		{
			if ((biggest.out)[i] != EMPTY)
				break ;
			i++;
			if (i == piles.elems)
				place_element_on_top_a(piles, find_biggest(piles, piles.a));		
		}
		k++;
	}
	while (pile_size(piles, piles.b))
	{
		rev_rotate_b(piles);
		define_properties_a(piles, &a);
		define_properties_b(piles, &b);
		while (b.on_top > a.on_top)
		{
			rotate_a(piles);
			define_properties_a(piles, &a);
			define_properties_b(piles, &b);
		}
		push_a(piles);
	}
	place_element_on_top_a(piles, find_smallest(piles, piles.a));
	
	// if (out)
	// 	free(out);
	// if(biggest.out != out && biggest.out);
	// 	free(biggest.out);
	// printf("Conclusion: i = %ld | %d\n", biggest.first_nbr, biggest.in_valid_order);
}

static int	push_swap(char **args, int size)
{
	t_pushSwap	piles;

	piles = get_piles(args, size);
	if (!(piles.a) || !(piles.b))
		return (0);
	algorithm_dewey(piles);
	// algorithm_djimo(piles);
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