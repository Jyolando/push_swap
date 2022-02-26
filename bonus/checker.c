/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:17:16 by jyolando          #+#    #+#             */
/*   Updated: 2022/02/26 22:39:47 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*z1;
	unsigned char	*z2;

	z1 = (unsigned char *)s1;
	z2 = (unsigned char *)s2;
	if (*z1 == '\0')
		return (-(*z2));
	if (*z2 == '\0')
		return (*z1);
	while (*z1 != '\0' || *z2 != '\0')
	{
		if (*z1 != *z2)
			return (*z1 - *z2);
		z1++;
		z2++;
	}
	return (0);
}

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
		{
			free(arr);
			return (NULL);
		}
		i++;
	}
	return (arr);
}

static int	check_args(t_stack *a, t_stack *b, t_stack *init, char **v)
{
	init->tab = ft_parse_args(v, init->max_size);
	if (!init->tab || !ft_unique(init->tab, init->max_size))
	{
		free(init->tab);
		ft_error();
	}
	if (!ft_create_stacks(a, b, init, 1))
		return (0);
	return (1);
}

int	main(int c, char **v)
{
	t_stack	a;
	t_stack	b;
	t_stack	init;

	init.max_size = c - 1;
	if (init.max_size < 1)
		return (0);
	if (!check_args(&a, &b, &init, v))
		return (0);
	parse(&a, &b);
	free(a.tab);
	free(b.tab);
}
