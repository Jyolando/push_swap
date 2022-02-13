#include "../../../includes/push_swap.h"

void init_stacks(t_stack *a, t_stack *b, t_stacks *s)
{
	s->a = a;
	s->b = b;
}

void init_dir(t_directions *a, t_directions *b)
{
	a->r = 0;
	a->rr = 0;
	a->stack_name = 'a';
	b->r = 0;
	b->rr = 0;
	b->stack_name = 'b';
}

// FIND NEAR INDEX

int find_near(t_stacks s, int INDEX, int *arr)
{
	int i;

	i = 0;
	while (i < s.a->cur_size)
	{
		if (find_index(s.a->tab[i], arr, s.a->max_size) == INDEX + 1
			|| find_index(s.a->tab[i], arr, s.a->max_size) == INDEX - 1)
			return (i);
		i++;
	}
	return (-1);
}

void calculate_directions(t_stack s, t_stack_dir *dir, int *arr)
{
	
}

void select_directions(t_stacks s, t_stack_dir *dir, int *arr)
{
	int INDEX;
	int pos;

	INDEX = find_index(s.b->tab[dir->b_index], arr, s.a->max_size);
	pos = find_near(s, INDEX, arr);

}

void search_optimal(t_stacks s, int *arr)
{
	int			i;
	t_stack_dir dir;

	i = 0;
	while (i < s.b->cur_size)
	{
		dir.b_index = i;
		select_directions(s, &dir, arr);
		i++;
	}
}

void pushToA(t_stack *a, t_stack *b, int *arr)
{
	t_directions	a_dir;
	t_directions	b_dir;
	t_stacks		s;

	init_dir(&a_dir, &b_dir);
	init_stacks(a, b, &s);
	// while (b->cur_size)
	// {

	// }
	search_optimal(s, arr);
}
