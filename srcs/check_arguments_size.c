/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments_size.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchevrie <tchevrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 03:20:03 by tchevrie          #+#    #+#             */
/*   Updated: 2023/01/19 03:27:26 by tchevrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_arguments_size(char **args, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (ft_strlen(args[i]) == 0)
			return (ft_putstr_fd(ERR_WRONGTYPEARGS, 2), 0);
		i++;
	}
	return (1);
}
