/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fullsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:29:45 by jyolando          #+#    #+#             */
/*   Updated: 2022/02/13 22:44:40 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	full_sort(t_stack *a, t_stack *b)
{
	int *sorted_arr;

	sorted_arr = ft_insertion_sort(*a);

	int i = 0;
	while (i < a->cur_size)
	{
		printf("%d | ", sorted_arr[i++]);
	}
	printf("\n");

	pushToB(a, b, sorted_arr);
	pushToA(a, b, sorted_arr);
}

