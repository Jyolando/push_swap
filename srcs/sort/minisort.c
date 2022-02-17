/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minisort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:04:16 by jyolando          #+#    #+#             */
/*   Updated: 2022/02/18 00:38:25 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	sort_three(t_stack *s)
{
	if (ft_arr_sorted(*s))
		return ;
	if (s->cur_size == 2)
	{
		ft_swap(s, 0);
		return ;
	}
	if (s->tab[0] < s->tab[1] && s->tab[0] > s->tab[2] && s->tab[1] > s->tab[2])
		ft_reverse_rotate(s, s->cur_size, 0);
	else if (s->tab[0] > s->tab[1] && s->tab[0] > s->tab[2]
		&& s->tab[1] < s->tab[2])
		ft_rotate(s, s->cur_size, 0);
	else
		ft_swap(s, 0);
	if (s->tab[0] > s->tab[1])
		ft_rotate(s, s->cur_size, 0);
	if (s->tab[1] > s->tab[2])
		ft_reverse_rotate(s, s->cur_size, 0);
}

static void	merge(t_stack *a, t_stack *b)
{
	int	max_a;
	int	min;

	max_a = a->tab[2];
	min = a->info.min;
	while (b->cur_size > 0)
	{
		if (a->tab[0] > b->tab[0] || (b->tab[0] > max_a && a->tab[0] == min))
			ft_push(b, a);
		ft_rotate(a, a->cur_size, 0);
	}
	while (a->tab[0] != min)
		ft_rotate(a, a->cur_size, 0);
}

void	minisort(t_stack *a, t_stack *b)
{
	if (a->cur_size == 2)
	{
		ft_swap(a, 0);
		return ;
	}
	while (a->cur_size > 3)
		ft_push(a, b);
	sort_three(a);
	sort_three(b);
	merge(a, b);
}
