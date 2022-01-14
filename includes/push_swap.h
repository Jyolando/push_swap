/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 22:05:34 by jyolando          #+#    #+#             */
/*   Updated: 2022/01/14 20:08:18 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libs/Libft/libft.h"
#include <unistd.h>
#include <stdlib.h>


typedef struct s_info
{
	char stack_name;
}				t_info;

typedef struct s_stack
{
	int	*tab;
	int	cur_size;
	int	max_size;
	t_info info;
}               t_stack;

void	ft_putstr(char *str);
void	ft_error(void);

void	ft_swap(t_stack *src, int same);
void	ft_swap_same(t_stack *a, t_stack *b);
void	ft_push(t_stack *src, t_stack *dst);

void	ft_rotate(t_stack *src, int size, int same);
void	ft_rotate_same(t_stack *a, t_stack *b);


void	ft_reverse_rotate(t_stack *src, int size, int same);
void	ft_reverse_rotate_same(t_stack *a, t_stack *b);

void	ft_init_structs(t_stack *a, t_stack *b, int size);

int	ft_parse_atoi(const char *s, int *res);
int	ft_create_stacks(t_stack *a, t_stack *b, t_stack init);

#endif