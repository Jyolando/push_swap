/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:06:03 by jyolando          #+#    #+#             */
/*   Updated: 2022/02/16 12:06:03 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	push_to_b(t_stack *a, t_stack *b, int sort_size, int *arr)
{
	int	l;

	l = 0;
	while (a->cur_size)
	{
		if (l > 1 && find_index(a->tab[0], arr, a->max_size) <= l)
		{
			ft_push(a, b);
			ft_rotate(b, b->cur_size, 0);
			l++;
		}
		else if (find_index(a->tab[0], arr, a->max_size) <= l + sort_size)
		{
			ft_push(a, b);
			l++;
		}
		else if (find_index(a->tab[0], arr, a->max_size) >= l)
			ft_rotate(a, a->cur_size, 0);
	}
}
