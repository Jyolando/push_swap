/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:02:54 by                   #+#    #+#             */
/*   Updated: 2022/01/14 12:20:10 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_init_structs(t_stack *a, t_stack *b, int size)
{
	int	i;

	a->tab = (int *)malloc(sizeof(int) * size);
	b->tab = (int *)malloc(sizeof(int) * size);
	a->max_size = b->cur_size = size;
	a->cur_size = b->cur_size = size;
	a->info.stack_name = 'a';
	b->info.stack_name = 'b';
	i = 0;
	while (i < size)
	{
		a->tab[i] = b->tab[i] = 0;
		i++;
	}
}