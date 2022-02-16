/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:02:54 by                   #+#    #+#             */
/*   Updated: 2022/02/16 12:18:44 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_init_structs(t_stack *a, t_stack *b, int size)
{
	int	i;

	a->tab = (int *)malloc(sizeof(int) * size);
	b->tab = (int *)malloc(sizeof(int) * size);
	a->max_size = size;
	b->max_size = size;
	a->cur_size = size;
	b->cur_size = 0;
	a->info.stack_name = 'a';
	b->info.stack_name = 'b';
	i = 0;
	while (i < size)
	{
		a->tab[i] = 0;
		b->tab[i] = 0;
		i++;
	}
}
