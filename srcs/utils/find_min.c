/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:04:21 by jyolando          #+#    #+#             */
/*   Updated: 2022/02/16 11:51:15 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_min(t_stack s)
{
	int	min;
	int	i;

	i = 0;
	min = s.tab[i];
	while (i < s.cur_size)
	{
		if (s.tab[i] < min)
			min = s.tab[i];
		i++;
	}
	return (min);
}
