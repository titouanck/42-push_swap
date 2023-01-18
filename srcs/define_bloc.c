/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_bloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:53:08 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/18 19:14:04 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bloc	define_bloc_down(t_pushSwap piles, int nbr)
{
	t_bloc		bloc_down;

	bloc_down.min = (piles.size / 2) / nbr * nbr - nbr;
	bloc_down.max = bloc_down.min + (nbr - 1);
	bloc_down.valid = 1;
	return (bloc_down);
}

t_bloc	define_bloc_up(int nbr, t_bloc bloc_down)
{
	t_bloc		bloc_up;

	bloc_up.min = bloc_down.min + nbr;
	bloc_up.max = bloc_up.min + (nbr - 1);
	bloc_up.valid = 1;
	return (bloc_up);
}
