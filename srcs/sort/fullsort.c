/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fullsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:29:45 by jyolando          #+#    #+#             */
/*   Updated: 2022/02/18 01:18:42 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	full_sort(t_stack *a, t_stack *b)
{
	int	*arr;

	arr = ft_insertion_sort(*a);
	if (a->max_size <= 100)
		push_to_b(a, b, 15, arr);
	else
		push_to_b(a, b, 30, arr);
	push_to_a(a, b);
	free(arr);
}
