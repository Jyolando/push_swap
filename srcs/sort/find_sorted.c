#include "../../includes/push_swap.h"

#include <stdio.h>

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int *ft_fill_arr(t_stack a)
{
	int	i;
	int *arr;

	i = 0;
	arr = (int *)malloc(a.cur_size * sizeof(int));
	while (i < a.cur_size)
	{
		arr[i] = a.tab[i];
		i++;
	}
	return (arr);
}

int *ft_insertion_sort(t_stack a)
{
	int i;
	int j;
	int *arr;

	i = 1;
	arr = ft_fill_arr(a);
	while (i < a.cur_size)
	{
		if (arr[i] < arr[i - 1])
		{
			j = i;
			while(arr[j] < arr[j - 1] && j > 0)
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
