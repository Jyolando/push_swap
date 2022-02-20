/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:22:24 by                   #+#    #+#             */
/*   Updated: 2022/02/20 12:00:40 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_unique(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
			if (arr[i] == arr[j++])
				return (0);
		i++;
	}
	return (1);
}

static int	*ft_parse_args(char **v, int size)
{
	int	*arr;
	int	i;

	i = 0;
	arr = (int *)malloc(sizeof(int) * size);
	if (arr == NULL)
		ft_error();
	while (i < size)
	{
		if (!ft_parse_atoi(v[i + 1], &arr[i]))
			ft_error();
		i++;
	}
	return (arr);
}

int	ft_check_args(t_stack *a, t_stack *b, t_stack *init, char **v)
{
	init->tab = ft_parse_args(v, init->max_size);
	if (!init->tab || !ft_unique(init->tab, init->max_size))
	{
		free(init->tab);
		ft_error();
	}
	if (!ft_create_stacks(a, b, init, 0))
		return (0);
	return (1);
}

int	main(int c, char **v)
{
	t_stack	a;
	t_stack	b;
	t_stack	init;

	init.max_size = c - 1;
	if (!ft_check_args(&a, &b, &init, v))
		return (0);
	if (ft_arr_sorted(a) && ft_arr_ready(a))
	{
		free_stacks(&a, &b);
		return (0);
	}
	else if (a.cur_size <= 6)
	{
		a.info.min = find_min(a);
		minisort(&a, &b);
	}
	else
		full_sort(&a, &b);
	free_stacks(&a, &b);
	return (0);
}
