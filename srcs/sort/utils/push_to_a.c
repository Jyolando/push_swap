/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:07:41 by jyolando          #+#    #+#             */
/*   Updated: 2022/02/16 12:07:41 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

static int	max_num_s(t_stack *s)
{
	int	i;
	int	res;

	i = 0;
	res = s->tab[i];
	while (i < s->cur_size)
	{
		if (s->tab[i] > res)
			res = s->tab[i];
		i++;
	}
	return (res);
}

static int	*create_s_arr(t_stack *s)
{
	int	*arr;
	int	i;

	i = 0;
	arr = (int *)malloc(sizeof(int) * s->cur_size);
	if (!arr)
		return (NULL);
	while (i < s->cur_size)
	{
		arr[i] = s->tab[i];
		i++;
	}
	return (arr);
}

static int	search_rotate(t_stack *s, int max, int size)
{
	int	i;
	int	*arr;

	arr = create_s_arr(s);
	i = size;
	while (arr[size] != max)
		size--;
	i -= size;
	size = 0;
	while (arr[size] != max)
		size++;
	free(arr);
	if (i < size)
		return (RR);
	return (R);
}

void	push_to_a(t_stack *a, t_stack *b)
{
	int	max_num;

	while (b->cur_size)
	{
		max_num = max_num_s(b);
		if (b->tab[0] != max_num
			&& search_rotate(b, max_num, b->cur_size) == R)
			ft_rotate(b, b->cur_size, 0);
		else if (b->tab[0] != max_num
			&& search_rotate(b, max_num, b->cur_size) == RR)
			ft_reverse_rotate(b, b->cur_size, 0);
		else
			ft_push(b, a);
	}
}
