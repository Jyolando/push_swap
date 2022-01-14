/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 21:41:01 by                   #+#    #+#             */
/*   Updated: 2022/01/14 21:49:29 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int ft_gen_a(t_stack *a, int *arr, int size)
{
	int i;

	i = -1;
	a->tab = (int *) malloc(sizeof(int) * size);
	if (a->tab == NULL)
		return (0);
	while (i++ < size)
		a->tab[i] = arr[i];
	a->max_size = a->cur_size = size;
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
	return (1);
}

int	ft_create_stacks(t_stack *a, t_stack *b, t_stack init)
{
	if (!ft_gen_a(a, init.tab, init.max_size) || !ft_gen_b(b, init.max_size))
		ft_error(); // NOT FREED
	return (1);
}