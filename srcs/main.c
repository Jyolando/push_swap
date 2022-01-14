/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:22:24 by                   #+#    #+#             */
/*   Updated: 2022/01/14 22:04:58 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int ft_unique(int *arr, int size)
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

int *ft_parse_args(char **v, int size)
{
	int	*arr;
	int i;

	i = 0;
	arr = (int *)malloc(sizeof(int) * size);
	if (arr == NULL)
		ft_error();
	while (i < size)
	{
		if (!ft_parse_atoi(v[i + 1], &arr[i]))
			return (NULL);
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
	if (!ft_create_stacks(a, b, *init))
		return (0);
	return (1);
}

#include <stdio.h>

int main(int c, char **v)
{
	t_stack a;
	t_stack b;
	t_stack init;

	init.max_size = c - 1;
	if (init.max_size < 1)
		ft_error();
	if (!ft_check_args(&a, &b, &init, v))
		return (0);

	int i = 0;

	while (i < a.max_size)
		printf("%d | ", a.tab[i++]);

	return (0);
}