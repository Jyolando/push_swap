/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra_rrb_rrr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 11:31:34 by                   #+#    #+#             */
/*   Updated: 2022/01/14 11:53:22 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_reverse_rotate(t_stack *src, int size, int same)
{
	int	temp;
	int tempSec;
	int i;

	temp = src->tab[size - 1];
	i = 0;
	while (i < size)
	{
		tempSec = src->tab[i];
		src->tab[i] = temp;
		temp = tempSec;
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