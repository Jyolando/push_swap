/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:04:21 by jyolando          #+#    #+#             */
/*   Updated: 2022/02/01 15:26:07 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int find_min(t_stack s)
{
	int min;
	int i;

	min = s.tab[0];
	i = 0;
	while (i < s.cur_size - 1)
	{
		if (s.tab[i] > s.tab[i + 1] && min > s.tab[i + 1])
			min = s.tab[i + 1];
		i++;
	}
	return min;
}
