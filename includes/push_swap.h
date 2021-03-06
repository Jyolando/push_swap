/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 22:05:34 by jyolando          #+#    #+#             */
/*   Updated: 2022/02/20 14:24:23 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/Libft/libft.h"
# include <stdlib.h>

# define R 0
# define RR 1

typedef struct s_info
{
	char	stack_name;
	int		min;
}				t_info;

typedef struct s_stack
{
	int		*tab;
	int		cur_size;
	int		max_size;
	t_info	info;
}				t_stack;

void	ft_putstr(char *str);
void	ft_error(void);
void	free_stacks(t_stack *a, t_stack *b);
void	ft_swap(t_stack *src, int same);
void	ft_swap_same(t_stack *a, t_stack *b, int check);
void	ft_push(t_stack *src, t_stack *dst);
void	ft_rotate(t_stack *src, int size, int same);
void	ft_rotate_same(t_stack *a, t_stack *b, int check);
void	ft_reverse_rotate(t_stack *src, int size, int same);
void	ft_reverse_rotate_same(t_stack *a, t_stack *b, int check);
void	minisort(t_stack *a, t_stack *b);
void	full_sort(t_stack *a, t_stack *b);
void	push_to_b(t_stack *a, t_stack *b, int sort_size, int *arr);
void	push_to_a(t_stack *a, t_stack *b);

int		ft_parse_atoi(const char *s, int *res);
int		ft_arr_sorted(t_stack stack);
int		ft_create_stacks(t_stack *a, t_stack *b, t_stack *init, int check);
int		ft_check_args(t_stack *a, t_stack *b, t_stack *init, char **v);
int		ft_checker_args(t_stack *a, t_stack *b, t_stack *init, char **v);
int		ft_arr_ready(t_stack stack);
int		find_min(t_stack s);
int		ft_unique(int *arr, int size);
int		find_index(int num, int *arr, int size);

int		*ft_insertion_sort(t_stack a);

#endif
