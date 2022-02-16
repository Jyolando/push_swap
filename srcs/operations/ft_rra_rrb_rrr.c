/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra_rrb_rrr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 11:31:34 by                   #+#    #+#             */
/*   Updated: 2022/02/16 12:09:43 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_reverse_rotate(t_stack *src, int size, int same)
{
	int	temp;
	int	temp_sec;
	int	i;

	temp = src->tab[size - 1];
	i = 0;
	while (i < size)
	{
		temp_sec = src->tab[i];
		src->tab[i] = temp;
		temp = temp_sec;
		i++;
	}
	if (src->info.stack_name == 'a' && same == 0)
		ft_putstr("rra\n");
	else if (src->info.stack_name == 'b' && same == 0)
		ft_putstr("rrb\n");
}

void	ft_reverse_rotate_same(t_stack *a, t_stack *b)
{
	ft_reverse_rotate(a, a->cur_size, 1);
	ft_reverse_rotate(b, b->cur_size, 1);
	ft_putstr("rrr\n");
}
