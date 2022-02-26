/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 21:41:01 by                   #+#    #+#             */
/*   Updated: 2022/02/26 22:27:05 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap_bonus.h"

static void	ft_free(t_stack *a, t_stack *b)
{
	free(a->tab);
	free(b->tab);
	ft_error();
}

static void	check_stacks(char *line, t_stack *a, t_stack *b)
{
	if (!(ft_strcmp(line, "sa\n")))
		ft_swap(a, 0);
	else if (!(ft_strcmp(line, "sb\n")))
		ft_swap(b, 0);
	else if (!(ft_strcmp(line, "ss\n")))
		ft_swap_same(a, b, 1);
	else if (!(ft_strcmp(line, "pa\n")))
		ft_push(b, a);
	else if (!(ft_strcmp(line, "pb\n")))
		ft_push(a, b);
	else if (!(ft_strcmp(line, "ra\n")))
		ft_rotate(a, a->cur_size, 0);
	else if (!(ft_strcmp(line, "rb\n")))
		ft_rotate(b, b->cur_size, 0);
	else if (!(ft_strcmp(line, "rr\n")))
		ft_rotate_same(a, b, 1);
	else if (!(ft_strcmp(line, "rra\n")))
		ft_reverse_rotate(a, a->cur_size, 0);
	else if (!(ft_strcmp(line, "rrb\n")))
		ft_reverse_rotate(b, b->cur_size, 0);
	else if (!(ft_strcmp(line, "rrr\n")))
		ft_reverse_rotate_same(a, b, 1);
	else
		ft_free(a, b);
}

void	parse(t_stack *a, t_stack *b)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		check_stacks(line, a, b);
		free(line);
		line = get_next_line(0);
	}
	if (b->cur_size == 0 && ft_arr_sorted(*a))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}
