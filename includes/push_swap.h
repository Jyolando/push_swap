/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 22:05:34 by jyolando          #+#    #+#             */
/*   Updated: 2022/02/16 11:31:37 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libs/Libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

#define R 0
#define RR 1

typedef struct s_info
{
	char stack_name;
	int min;
}				t_info;

typedef struct s_directions
{
	int elem;
	int dir;
	int r_count;
}				t_directions;

typedef struct s_stack_dir
{
	t_directions a;
	t_directions b;
	int summ;
}				t_stack_dir;

typedef struct s_stack
{
	int	*tab;
	int *markup;
	int	cur_size;
	int	max_size;
	t_info info;
}               t_stack;

typedef struct s_stacks
{
	t_stack *a;
	t_stack *b;
}				t_stacks;


void	ft_putstr(char *str);
void	ft_error(void);

void	minisort(t_stack *a, t_stack *b);

void	ft_swap(t_stack *src, int same);
void	ft_swap_same(t_stack *a, t_stack *b);
void	ft_push(t_stack *src, t_stack *dst);
void	ft_rotate(t_stack *src, int size, int same);
void	ft_rotate_same(t_stack *a, t_stack *b);
void	ft_reverse_rotate(t_stack *src, int size, int same);
void	ft_reverse_rotate_same(t_stack *a, t_stack *b);
int		*ft_insertion_sort(t_stack a);
void	full_sort(t_stack *a, t_stack *b);
void pushToB(t_stack *a, t_stack *b, int *arr, int sort_size);
void	free_stack(t_stack *s);
void	update_markup(t_stack *a, int m_head);
int		find_index(int num, int *arr, int size);
void pushToA(t_stack *a, t_stack *b);
int max_index_in_stack(t_stack *s, int *arr);

t_stack	copy_stack(t_stack s);

void	ft_init_structs(t_stack *a, t_stack *b, int size);

int	ft_parse_atoi(const char *s, int *res);
int	ft_create_stacks(t_stack *a, t_stack *b, t_stack init);
int	ft_arr_sorted(t_stack stack);
int	ft_arr_ready(t_stack stack);
int find_min(t_stack s);
int	*copy_sa_arr(int *tab, int size);

#endif
