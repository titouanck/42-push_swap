/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:39:20 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/03 14:34:24 by tchevrie         ###   ########.fr       */
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

typedef struct s_pushSwap
{
	long	*a;
	long	*b;
	int		size;
}			t_pushSwap;

typedef struct s_inPile
{
	long	smallest;
	long	biggest;
	int		elems;
}			t_inPile;


/* Operations */
int		swap_ab(t_pushSwap piles);
int		swap_a(t_pushSwap piles);
int		swap_b(t_pushSwap piles);
int		push_a(t_pushSwap piles);
int		push_b(t_pushSwap piles);
int		rotate_ab(t_pushSwap piles);
int		rotate_a(t_pushSwap piles);
int		rotate_b(t_pushSwap piles);
int		rev_rotate_ab(t_pushSwap piles);
int		rev_rotate_a(t_pushSwap piles);
int		rev_rotate_b(t_pushSwap piles);

/* Algorithm */
void	algo_2_elements_a(t_pushSwap piles);
void	algo_2_elements_b(t_pushSwap piles);
void	algo_3_elements_a(t_pushSwap piles);
void	algo_3_elements_b(t_pushSwap piles);

/* Utilities */
t_pushSwap	get_piles(char **args, int size);
void		print_piles(t_pushSwap piles);
void		ft_swap(long *a, long *b);
long		find_smallest(t_pushSwap piles, long *pile);
long		find_biggest(t_pushSwap piles, long *pile);
int			pile_size(t_pushSwap piles, long *pile);
#endif