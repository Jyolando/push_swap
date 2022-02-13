/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 21:41:01 by                   #+#    #+#             */
/*   Updated: 2022/02/13 16:00:41 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int ft_gen_a(t_stack *a, int *arr, int size)
{
	int i;

	i = -1;
	a->tab = (int *) malloc(sizeof(int) * size);
	a->markup = (int *)malloc(sizeof(int) * size);
	if (a->tab == NULL)
		return (0);
	while (i++ < size)
		a->tab[i] = arr[i];
	a->max_size = a->cur_size = size;
	a->info.stack_name = 'a';
	return (1);
}

static int ft_gen_b(t_stack *b, int size)
{
	int i;

	i = 0;
	b->tab = (int *)malloc(sizeof(int) * size);
	if (b->tab == NULL)
		return (0);
	while (i < size)
		b->tab[i++] = 0;
	b->max_size = size;
	b->cur_size = 0;
	b->info.stack_name = 'b';
	return (1);
}

void	free_stack(t_stack *s)
{
	free(s->tab);
	free(s->markup);
}

t_stack	copy_stack(t_stack s)
{
	t_stack	new;
	int		i;

	new.tab = (int *)malloc(sizeof(int) * s.max_size);
	new.markup = (int *)malloc(sizeof(int) * s.max_size);
	new.cur_size = s.cur_size;
	new.max_size = s.max_size;
	i = 0;
	while (i < s.cur_size)
	{
		new.tab[i] = s.tab[i];
		i++;
	}
	return (new);
}


int	ft_create_stacks(t_stack *a, t_stack *b, t_stack init)
{
	if (!ft_gen_a(a, init.tab, init.max_size) || !ft_gen_b(b, init.max_size))
		ft_error(); // NOT FREED
	return (1);
}
