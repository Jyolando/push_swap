/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra_rb_rr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 23:58:23 by                   #+#    #+#             */
/*   Updated: 2022/02/16 12:11:29 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_rotate(t_stack *src, int size, int same)
{
	int	temp;
	int	temp_sec;
	int	temp_th;
	int	flag;

	flag = 0;
	temp_th = src->tab[0];
	while (size--)
	{
		if (flag)
		{
			temp_sec = src->tab[size];
			src->tab[size] = temp;
			temp = temp_sec;
			continue ;
		}
		temp = src->tab[size];
		src->tab[size] = 0;
		flag = 1;
	}
	src->tab[src->cur_size - 1] = temp_th;
	if (src->info.stack_name == 'a' && same == 0)
		ft_putstr("ra\n");
	else if (src->info.stack_name == 'b' && same == 0)
		ft_putstr("rb\n");
}

void	ft_rotate_same(t_stack *a, t_stack *b)
{
	ft_rotate(a, a->cur_size, 1);
	ft_rotate(b, b->cur_size, 1);
	ft_putstr("rr\n");
}
