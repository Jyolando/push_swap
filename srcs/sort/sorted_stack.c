/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 01:18:17 by jyolando          #+#    #+#             */
/*   Updated: 2022/02/18 01:18:30 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int	*ft_fill_arr(t_stack a)
{
	int	i;
	int	*arr;

	i = 0;
	arr = (int *)malloc(a.cur_size * sizeof(int));
	while (i < a.cur_size)
	{
		arr[i] = a.tab[i];
		i++;
	}
	return (arr);
}

int	*ft_insertion_sort(t_stack a)
{
	int	i;
	int	j;
	int	*arr;

	i = 1;
	arr = ft_fill_arr(a);
	while (i < a.cur_size)
	{
		if (arr[i] < arr[i - 1])
		{
			j = i;
			while (arr[j] < arr[j - 1] && j > 0)
			{
				swap(&arr[j], &arr[j - 1]);
				if (j - 1 > 0)
					j--;
			}
		}
		i++;
	}
	return (arr);
}
