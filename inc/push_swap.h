/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:39:20 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/02 18:10:46 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

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
	int	smallet;
	int	s_index;
	int	biggest;
	int	b_index;
}		t_inPile;


/* Operations */
void		swap_ab(t_pushSwap piles);
void		swap_a(t_pushSwap piles);
void		swap_b(t_pushSwap piles);
void		push_a(t_pushSwap piles);
void		push_b(t_pushSwap piles);
void		rotate_ab(t_pushSwap piles);
void		rotate_a(t_pushSwap piles);
void		rotate_b(t_pushSwap piles);
void		rev_rotate_ab(t_pushSwap piles);
void		rev_rotate_a(t_pushSwap piles);
void		rev_rotate_b(t_pushSwap piles);

t_pushSwap	get_piles(char **args, int size);

/* Utilities */
void		print_piles(t_pushSwap piles);
void		ft_swap(long *a, long *b);

#endif