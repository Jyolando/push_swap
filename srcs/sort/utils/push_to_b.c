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

void	push_to_b(t_stack *a, t_stack *b, int sort_size)
{
	int	l;

	l = 0;
	while (a->cur_size)
	{
		if (l > 1 && a->tab[0] <= l)
		{
			ft_push(a, b);
			ft_rotate(b, b->cur_size, 0);
			l++;
		}
		else if (a->tab[0] <= l + sort_size)
		{
			ft_push(a, b);
			l++;
		}
		else if (a->tab[0] >= l)
			ft_rotate(a, a->cur_size, 0);
	}
}
