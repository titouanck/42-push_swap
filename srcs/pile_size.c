/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:05:13 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/18 18:14:27 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pile_size(t_pushSwap piles, t_elem *pile)
{
	int	i;

	i = 0;
	while (i < piles.size)
	{
		if ((pile + i)->nbr != EMPTY)
			break ;
		i++;
	}
	return (piles.size - i);
}
