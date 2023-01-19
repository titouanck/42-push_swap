/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:59:28 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/19 02:26:27 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

// # define ERR_ALLOC "Error: failed to allocate memory.\n"
// # define ERR_WRONGTYPEARGS "Error: wrong type of arguments.\n"
// # define ERR_DUPLICATEARGS "Error: duplicate arguments.\n"
// # define ERR_BIGGERTHANINT "Error: argument does not fit in an int.\n"

# define ERR_ALLOC "Error\n"
# define ERR_WRONGTYPEARGS "Error\n"
# define ERR_DUPLICATEARGS "Error\n"
# define ERR_BIGGERTHANINT "Error\n"

# define EMPTY 4815162342

/* Operations are stored in a linked list of integers */
# define NONE -42

# define SA 0
# define SB 1
# define SS 2

# define PA 3
# define PB 4

# define RA 5
# define RB 6
# define RR 7

# define RRA 8
# define RRB 9
# define RRR 10

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

typedef struct s_operation
{
	int					operation;
	struct s_operation	*next;
}						t_operation;

typedef struct s_pushSwap
{
	t_elem		*a;
	t_elem		*b;
	t_elem		*original_a;
	t_elem		*original_b;
	int			size;
	t_operation	*operations;
}			t_pushSwap;

typedef struct s_numbers
{
	t_elem	nearest;
	t_elem	smallest;
	t_elem	sec_smallest;
	t_elem	biggest;
	t_elem	sec_biggest;
	t_elem	ontop;
}			t_numbers;

typedef struct s_ij
{
	int	i;
	int	j;
}		t_ij;

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

// actions.c
void		actions_smallest_on_top_a(t_pushSwap piles);
void		actions_sec_smallest_on_top_a(t_pushSwap piles);
void		actions_biggest_on_top_a(t_pushSwap piles);

// algo_blocs.c
void		algo_blocs(t_pushSwap piles, int nbr);

// algorithm.c
void		algorithm(t_pushSwap piles);

// define_bloc.c
t_bloc		define_bloc_down(t_pushSwap piles, int nbr);
t_bloc		define_bloc_up(int nbr, t_bloc bloc_down);

// define_properties.c
t_numbers	define_properties(t_pushSwap piles, t_elem *pile);

// find.c
t_elem		find_ontop(t_pushSwap piles, t_elem *pile);
t_elem		find_biggest(t_pushSwap piles, t_elem *pile);
t_elem		find_sec_biggest(t_pushSwap piles, t_elem *pile);
t_elem		find_smallest(t_pushSwap piles, t_elem *pile);
t_elem		find_sec_smallest(t_pushSwap piles, t_elem *pile);

// find_nearest.c
t_elem		find_nearest(t_pushSwap piles, t_elem *pile, t_numbers numbers);
t_elem		find_closest_one(t_pushSwap piles, t_elem *pile, long a, long b);
t_elem		\
find_nearest_inrange(t_pushSwap piles, t_elem *pile, long min, long max);

// get_piles.c
t_pushSwap	get_piles(char **args, int size);

// ft_atoi_long.c
long		ft_atoi_long(const char *str);

// mini_algos.c
void		algo_2_elements_a(t_pushSwap piles);
void		algo_3_elements_a(t_pushSwap piles);
void		algo_19_elements_a(t_pushSwap piles);
void		algo_100_elements_a(t_pushSwap piles);
void		algo_750_elements_a(t_pushSwap piles);

// on_top.c
void		place_element_on_top_a(t_pushSwap piles, t_elem elem);
void		place_element_on_top_b(t_pushSwap piles, t_elem elem);

// operations.c
int			count_operations(t_pushSwap piles);
void		free_operations(t_pushSwap piles);
t_operation	*new_operation(t_pushSwap piles, int operation);

// pile_size.c
int			pile_size(t_pushSwap piles, t_elem *pile);

// pile_sorted.c
int			pile_sorted(t_pushSwap piles, t_elem *pile);

// print_operations.c
void		print_operations(t_pushSwap piles);

// print_piles.c
void		print_piles(t_pushSwap piles);

// set_piles.c
void		reset_piles(t_pushSwap piles);
t_pushSwap	duplicate_piles(t_pushSwap piles);

#endif
