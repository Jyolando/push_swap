/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 22:20:48 by                   #+#    #+#             */
/*   Updated: 2022/01/14 22:23:09 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_arr_sorted(t_stack stack)
{
	int i;

	i = 0;
	while (i < stack.cur_size - 1)
	{
		if (stack.tab[i] > stack.tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_arr_ready(t_stack stack)
{
	if (stack.cur_size == stack.max_size)
		return (1);
	return (0);
}