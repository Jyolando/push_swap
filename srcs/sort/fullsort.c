/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fullsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:29:45 by jyolando          #+#    #+#             */
/*   Updated: 2022/02/13 01:26:07 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int find_index(int num, int *arr, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (num == arr[i])
			return (i);
		i++;
	}
	return (i);
}

int *copy_sa_arr(int *tab, int size)
{
	int i;
	int *arr;

	i = 2;
	arr = (int *)malloc(sizeof(int) * size);
	if (arr == NULL)
		return (NULL);
	arr[0] = tab[1];
	arr[1] = tab[0];
	while (i < size)
	{
		arr[i] = tab[i];
		i++;
	}
	return (arr);
}

void update_markup(t_stack *a, int m_head) {
	int i;
	int j;
	int temp;

	i = 0;
	j = 0;
	temp = m_head;
	while (a->tab[i] != m_head)
		i++;
	while (j < a->cur_size)
	{
		if (a->tab[i] < temp) {
			a->markup[i] = 0;
		}
		else
		{
			temp = a->tab[i];
			a->markup[i] = 1;
		}
		i++;
		if (i == a->cur_size)
			i = 0;
		j++;
	}

	i = 0;
	// while (i < a->cur_size)
	// 	printf("\n | %d", a->markup[i++]);
}

int checkFalse(int *tab, int size, int m_head)
{
	int i;
	int j;
	int temp;
	int count;

	i = 0;
	j = 0;
	temp = m_head;
	count = 0;
	while (tab[i] != m_head)
		i++;
	while (j < size)
	{
		if (tab[i] < temp)
			count++;
		else if (tab[i] >= temp) {
			temp = tab[i];

		}
		i++;
		if (i == size)
			i = 0;
		j++;
		//!printf("temp = %d\n", temp);
	}
	//!printf("c = %d\n\n", count);
	return count;
}

int sa_needed(int *tab, int size, int m_head)
{
	int *c_tab;

	c_tab = copy_sa_arr(tab, size);
	if (checkFalse(tab, size, m_head) > checkFalse(c_tab, size, m_head))
	{
		free(c_tab);
		return (1);
	}
	free(c_tab);
	return (0);
}

void pushToB(t_stack *a, t_stack *b, int *arr)
{
	int m_head;
	int i = 0;

	printf("Stack A: ");
		while (i < a->cur_size)
			printf("%d | ", a->tab[i++]);
		printf("\n");

		i = 0;
		printf("Stack B: ");
		while (i < b->cur_size)
			printf("%d | ", b->tab[i++]);
		printf("\n");

	m_head = arr[0];
	while (checkFalse(a->tab, a->cur_size, m_head))
	{
		update_markup(a, m_head);
		if (sa_needed(a->tab, a->cur_size, m_head)) {
			ft_swap(a, 0);
			update_markup(a, m_head);
		} else if (a->markup[0] == 0)
			ft_push(a, b);
		else
			ft_rotate(a, a->cur_size, 0);

		i = 0;
		printf("Stack A: ");
		while (i < a->cur_size)
			printf("%d | ", a->tab[i++]);
		printf("\n");

		i = 0;
		printf("A Markuo: ");
		while (i < a->cur_size)
			printf("%d | ", a->markup[i++]);
		printf("\n");

		i = 0;
		printf("Stack B: ");
		while (i < b->cur_size)
			printf("%d | ", b->tab[i++]);
		printf("\n");
	}
}

void	full_sort(t_stack *a, t_stack *b)
{
	int *sorted_arr;

	sorted_arr = ft_insertion_sort(*a);

	int i = 0;
	while (i < a->cur_size)
	{
		printf("%d | ", sorted_arr[i++]);
	}
	printf("\n");

	pushToB(a, b, sorted_arr);
}
