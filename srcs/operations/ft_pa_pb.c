/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa_pb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 23:01:50 by                   #+#    #+#             */
/*   Updated: 2022/01/14 00:31:22 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	ft_move_back_array(t_stack *src, int size)
{
	size += 1;
	while (size--)
		src->tab[size] = src->tab[size - 1];
}

static void	ft_move_top_array(t_stack *src, int size)
{
	int	temp;
	int	temp_sec;
	int	flag;

	flag = 0;
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
}

void	ft_push(t_stack *src, t_stack *dst)
{
	if (!src || !dst || src->cur_size == 0)
		return ;
	ft_move_back_array(dst, dst->cur_size);
	dst->tab[0] = src->tab[0];
	dst->cur_size++;
	ft_move_top_array(src, src->cur_size);
	src->cur_size--;
	if (dst->info.stack_name == 'a')
		ft_putstr("pa\n");
	else if (dst->info.stack_name == 'b')
		ft_putstr("pb\n");
}
