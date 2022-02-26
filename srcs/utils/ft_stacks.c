/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 21:41:01 by                   #+#    #+#             */
/*   Updated: 2022/02/26 22:36:48 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	ft_gen_a(t_stack *a, int *arr, int size, int check)
{
	int	i;

	i = -1;
	a->tab = (int *)malloc(sizeof(int) * size);
	if (a->tab == NULL)
		return (0);
	while (i++ < size)
		a->tab[i] = arr[i];
	a->max_size = size;
	a->cur_size = size;
	if (!check)
		a->info.stack_name = 'a';
	return (1);
}

static int	ft_gen_b(t_stack *b, int size, int check)
{
	int	i;

	i = 0;
	b->tab = (int *)malloc(sizeof(int) * size);
	if (b->tab == NULL)
		return (0);
	while (i < size)
		b->tab[i++] = 0;
	b->max_size = size;
	b->cur_size = 0;
	if (!check)
		b->info.stack_name = 'b';
	return (1);
}

void	free_stacks(t_stack *a, t_stack *b)
{
	free(a->tab);
	free(b->tab);
}

int	ft_create_stacks(t_stack *a, t_stack *b, t_stack *init, int check)
{
	if (!ft_gen_a(a, init->tab, init->max_size, check)
		|| !ft_gen_b(b, init->max_size, check))
	{
		free_stacks(a, b);
		free(init->tab);
		ft_error();
	}
	free(init->tab);
	return (1);
}
