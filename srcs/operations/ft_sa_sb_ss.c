/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa_sb_ss.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 22:11:08 by jyolando          #+#    #+#             */
/*   Updated: 2022/01/31 18:41:18 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_swap(t_stack *src, int same)
{
	int	temp;

	if (!src || src->cur_size < 2)
		return ;
	temp = src->tab[0];
	src->tab[0] = src->tab[1];
	src->tab[1] = temp;
	if (src->info.stack_name == 'a' && same == 0)
		ft_putstr("sa\n");
	else if (src->info.stack_name == 'b' && same == 0)
		ft_putstr("sb\n");
}

void	ft_swap_same(t_stack *a, t_stack *b)
{
	ft_swap(a, 1);
	ft_swap(b, 1);
	ft_putstr("ss\n");
}
