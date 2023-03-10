/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:10:53 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/18 19:37:31 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(long *a, long *b)
{
	long	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
