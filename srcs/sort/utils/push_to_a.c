#include "../../../includes/push_swap.h"

void init_stacks(t_stack *a, t_stack *b, t_stacks *s)
{
	s->a = a;
	s->b = b;
}

// void init_dir(t_directions *a, t_directions *b)
// {
// 	a->r = 0;
// 	a->rr = 0;
// 	a->stack_name = 'a';
// 	b->r = 0;
// 	b->rr = 0;
// 	b->stack_name = 'b';
// }


// FIND NEAR INDEX

int find_index_in_stack(t_stack *s, int num)
{
	int	i;

	i = 0;
	while (i < s->cur_size)
	{
		if (s->tab[i] == num)
			return i;
		i++;
	}
	return (i);
}

int calculate_directions(t_stack *s, int num)
{
	if (find_index_in_stack(s, num) >= s->cur_size / 2)
		return (s->cur_size - find_index_in_stack(s, num));
	else
		return (find_index_in_stack(s, num));
}

int find_near(t_stack_dir *dir, t_stacks s, int *arr)
{
	int i;
	int elem_i;
	int temp_num;
	int res_num;

	i = 0;
	temp_num = -1;
	res_num = -1;
	while (i < s.a->cur_size)
	{
		elem_i = find_index(dir->b.elem, arr, s.b->cur_size);
		if (elem_i == find_index(s.a->tab[i], arr, s.a->cur_size) + 1
			|| elem_i == find_index(s.a->tab[i], arr, s.a->cur_size) - 1)
		{
			temp_num = find_index_in_stack(s.a, s.a->tab[i]);
			if (res_num == -1)
				temp_num = s.a->tab[i];
			else if (calculate_directions(s.a, s.a->tab[i]) < calculate_directions(s.a, res_num))
				res_num = s.a->tab[i];
		}
		i++;
	}
	return (res_num);
}

void init_dir(t_stack_dir *dir, int f_elem, int s_elem)
{
	dir->a.elem = f_elem;
	dir->b.elem = s_elem;
}

t_stack_dir search_optimal(t_stacks s, int *arr)
{
	int			i;
	int			j;
	t_stack_dir n_dir;
	t_stack_dir res_dir;

	res_dir.summ = -1;
	i = 0;
	while (i < s.b->cur_size)
	{
		init_dir(&n_dir, s.a->tab[i], s.b->tab[j]);
		printf("res for %d - %d\n",n_dir.b.elem,  find_near(&n_dir, s, arr));
		//printf("1\n");
		// if (n_dir.summ < res_dir.summ || res_dir.summ == -1)
		// 	res_dir = n_dir;
		i++;
	}
	return (res_dir);
}

static void move_b(t_stacks s, t_stack_dir dir)
{
	while (s.a->tab[0] != dir.a.elem || s.b->tab[0] != dir.b.elem)
	{
		if (s.a->tab[0] != dir.a.elem && s.b->tab[0] != dir.b.elem &&
			dir.a.dir == 1 && dir.b.dir == 1)
			ft_rotate_same(s.a, s.b);
		else if (s.a->tab[0] != dir.a.elem && s.b->tab[0] != dir.b.elem &&
			dir.a.dir == 0 && dir.b.dir == 0)
			ft_reverse_rotate_same(s.a, s.b);
		else {
			if (s.a->tab[0] != dir.a.elem && dir.a.dir == 1)
				ft_rotate(s.a, s.a->cur_size, 0);
			else if (s.a->tab[0] != dir.a.elem && dir.a.dir == 0)
				ft_reverse_rotate(s.a, s.a->cur_size, 0);
			if (s.b->tab[0] != dir.b.elem && dir.b.dir == 1)
				ft_rotate(s.b, s.b->cur_size, 0);
			else if (s.b->tab[0] != dir.b.elem && dir.b.elem == 0)
				ft_reverse_rotate(s.b, s.b->cur_size, 0);
		}
	}
}

static void move_sa(t_stacks s)
{
	if (s.a->tab[0] > s.a->tab[1])
		ft_swap(s.a, 0);
}

void pushToA(t_stack *a, t_stack *b, int *arr)
{
	t_stack_dir 	dir;
	t_stacks		s;

	//init_dir(&a_dir, &b_dir);
	init_stacks(a, b, &s);
	dir = search_optimal(s, arr);
	// dir.a.elem = 2;
	// dir.a.dir = 1;
	// dir.b.elem = 3;
	// dir.b.dir = 0;
	// move_b(s, dir);
	// ft_push(b, a);
	// move_sa(s);



	//print STACKS

	// int i = 0;
	// printf("A: ");
	// while (i < a->cur_size)
	// {
	// 	printf("| %d - [ %d ] ", a->tab[i], find_index(a->tab[i], arr, a->max_size));
	// 	i++;
	// }
	// printf("\n");
	// i = 0;
	// printf("B: ");
	// while (i < b->cur_size)
	// {
	// 	printf("| %d - [ %d ] ", b->tab[i], find_index(b->tab[i], arr, a->max_size));
	// 	i++;
	// }
	// printf("\n");
	// while (b->cur_size)
	// {

	// }
	//search_optimal(s, arr);
}
