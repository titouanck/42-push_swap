/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:39:20 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/17 18:31:47 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>

# define ERR_ALLOC "push_swap: failed to allocate memory.\n"
# define ERR_WRONGTYPEARGS "push_swap: wrong type of arguments.\n"
# define ERR_DUPLICATEARGS "push_swap: duplicate arguments.\n"

# define EMPTY 4815162342

# define DIR_UP 0
# define DIR_DOWN 1

typedef struct s_elem
{
	long	nbr;
	long	index;
}			t_elem;

typedef struct s_bloc
{
	int		valid;
	long	min;
	long	max;
	t_elem	nearest;
}			t_bloc;

typedef struct s_pushSwap
{
	t_elem	*a;
	t_elem	*b;
	int		size;
}			t_pushSwap;

typedef struct s_numbers
{
	t_elem	nearest;
	t_elem	smallest;
	t_elem	sec_smallest;
	t_elem	biggest;
	t_elem	ontop;
}			t_numbers;


/* Operations */
int			swap_ab(t_pushSwap piles);
int			swap_a(t_pushSwap piles);
int			swap_b(t_pushSwap piles);
int			push_a(t_pushSwap piles);
int			push_b(t_pushSwap piles);
int			rotate_ab(t_pushSwap piles);
int			rotate_a(t_pushSwap piles);
int			rotate_b(t_pushSwap piles);
int			rev_rotate_ab(t_pushSwap piles);
int			rev_rotate_a(t_pushSwap piles);
int			rev_rotate_b(t_pushSwap piles);

/* Utilities */
t_pushSwap	get_piles(char **args, int size);
void		print_piles(t_pushSwap piles);
void		ft_swap(long *a, long *b);
int			pile_size(t_pushSwap piles, t_elem *pile);
void		algorithm(t_pushSwap piles);
t_elem		find_nearest(t_pushSwap piles, t_elem *pile, t_numbers numbers);
t_elem		find_smallest(t_pushSwap piles, t_elem *pile);
t_elem		find_biggest(t_pushSwap piles, t_elem *pile);
t_numbers	define_properties(t_pushSwap piles, t_elem *pile);
t_elem		find_ontop(t_pushSwap piles, t_elem *pile);
int			pile_sorted(t_pushSwap piles, t_elem *pile);
void		place_element_on_top_a(t_pushSwap piles, t_elem elem);
void		place_element_on_top_b(t_pushSwap piles, t_elem elem);
t_elem		find_sec_smallest(t_pushSwap piles, t_elem *pile);
void		actions_sec_smallest_on_top_a(t_pushSwap piles);
void		actions_smallest_on_top_a(t_pushSwap piles);
void		actions_biggest_on_top_a(t_pushSwap piles);
t_elem		find_nearest_inrange(t_pushSwap piles, t_elem *pile, long min, long max);
t_elem		find_closest_one(t_pushSwap piles, t_elem *pile, long a, long b);
#endif