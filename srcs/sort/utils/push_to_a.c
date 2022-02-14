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

void calculate_summ(t_stacks s, t_stack_dir *dir)
{
	if (find_index_in_stack(s.a, dir->a.elem) >= s.a->cur_size / 2)
	{
		dir->a.r_count = s.a->cur_size - find_index_in_stack(s.a, dir->a.elem);
		dir->a.dir = 0;
	}
	else
	{
		dir->a.r_count = s.a->cur_size;
		dir->a.dir = 1;
	}
	if (find_index_in_stack(s.b, dir->b.elem) >= s.b->cur_size / 2)
	{
		dir->b.r_count = s.b->cur_size - find_index_in_stack(s.b, dir->b.elem);
		dir->b.dir = 0;
	}
	else
	{
		dir->b.r_count = s.b->cur_size;
		dir->b.dir = 1;
	}
	dir->summ = dir->a.r_count + dir->b.r_count;
}

int calculate_directions(t_stack *s, int num)
{
	if (find_index_in_stack(s, num) >= s->cur_size / 2)
		return (s->cur_size - find_index_in_stack(s, num));
	else
		return (find_index_in_stack(s, num));
}

void find_near(t_stack_dir *dir, t_stacks s, int *arr)
{
	int i;
	int elem_i;

	i = 0;
	dir->a.elem = -1;
	while (i < s.a->cur_size)
	{
		elem_i = find_index(dir->b.elem, arr, s.a->max_size);
		//!printf("index b_elem: %d - index a_elem: %d\n", elem_i, find_index(s.a->tab[i], arr, s.a->max_size));
		//!printf("num a_elem: %d\n", s.a->tab[i]);
		//printf("%d\n", elem_i);
		if (elem_i == find_index(s.a->tab[i], arr, s.a->max_size) + 1
			|| elem_i == find_index(s.a->tab[i], arr, s.a->max_size) - 1)
		{
			//!printf("OK for num B_ELEM %d || for num A_ELEM %d\n", dir->b.elem, s.a->tab[i]);
			if (dir->a.elem == -1)
				dir->a.elem = s.a->tab[i];
			else if (calculate_directions(s.a, s.a->tab[i]) < calculate_directions(s.a, dir->a.elem))
			{
				dir->a.elem = s.a->tab[i];
			}
		}
		i++;
	}
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
		init_dir(&n_dir, s.a->tab[i], s.b->tab[i]);
		//!printf("Cur b elem: %d\n", n_dir.b.elem);
		find_near(&n_dir, s, arr);
		//!printf("res for %d - %d\n\n", n_dir.b.elem, n_dir.a.elem);
		if (n_dir.a.elem != -1)
		{
			calculate_summ(s, &n_dir);
			if (res_dir.summ == -1 || n_dir.summ < res_dir.summ)
				res_dir = n_dir;
		}
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
			else if (s.b->tab[0] != dir.b.elem && dir.b.dir == 0)
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
	while (b->cur_size)
	{
		init_stacks(a, b, &s);
		dir = search_optimal(s, arr);
		move_b(s, dir);
		ft_push(b, a);
	}
	if (a->tab[0] != arr[0])
	{
		if (find_index_in_stack(a, arr[0]) >= a->cur_size / 2)
			while (a->tab[0] != arr[0])
				ft_reverse_rotate(a, a->cur_size, 0);
		else
			while (a->tab[0] != arr[0])
				ft_rotate(a, a->cur_size, 0);
	}


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
