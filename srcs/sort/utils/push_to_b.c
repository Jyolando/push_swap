#include "../../../includes/push_swap.h"

static int	checkFalse(int *tab, int size, int m_head)
{
	int	i;
	int	j;
	int	temp;
	int	count;

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
		else if (tab[i] >= temp)
			temp = tab[i];
		i++;
		if (i == size)
			i = 0;
		j++;
	}
	return (count);
}

static int	sa_needed(int *tab, int size, int m_head)
{
	int	*c_tab;

	c_tab = copy_sa_arr(tab, size);
	if (checkFalse(tab, size, m_head) > checkFalse(c_tab, size, m_head))
	{
		free(c_tab);
		return (1);
	}
	free(c_tab);
	return (0);
}

static int	*compare_m_heads(t_stack a, t_stack b, int *arr, int cur)
{
	t_stack	fs;
	t_stack	ss;
	int		*res;

	fs = copy_stack(a);
	ss = copy_stack(b);
	res = (int *)malloc(sizeof(int) * 2);
	while (checkFalse(fs.tab, fs.cur_size, a.tab[cur]))
	{
		update_markup(&fs, a.tab[cur]);
		if (sa_needed(fs.tab, fs.cur_size, a.tab[cur]))
		{
			ft_swap(&fs, 0);
			update_markup(&fs, a.tab[cur]);
		}
		else if (fs.markup[0] == 0)
			ft_push(&fs, &ss);
		else
			ft_rotate(&fs, fs.cur_size, 0);
	}
	res[0] = fs.cur_size - checkFalse(fs.tab, fs.cur_size, a.tab[cur]);
	res[1] = a.tab[cur];
	free_stack(&fs);
	free_stack(&ss);
	return (res);
}

static int	find_m_head(t_stack a, t_stack b, int *arr)
{
	int	*temp;
	int	temp_res;
	int	m_head;
	int	i;

	i = 0;
	temp_res = 0;
	m_head = a.tab[0];
	while (i < a.max_size)
	{
		temp = compare_m_heads(a, b, arr, i);
		{
			if (temp[0] > temp_res)
				m_head = temp[1];
			else if (temp[0] == temp_res)
			{
				if (m_head > temp[1])
					m_head = temp[1];
			}
			temp_res = temp[0];
		}
		free(temp);
		i++;
	}
	return (m_head);
}

void	pushToB(t_stack *a, t_stack *b, int *arr)
{
	int	m_head;

	m_head = find_m_head(*a, *b, arr);
	update_markup(a, m_head);
	while (checkFalse(a->tab, a->cur_size, m_head))
	{
		if (sa_needed(a->tab, a->cur_size, m_head))
		{
			ft_swap(a, 0);
			update_markup(a, m_head);
		}
		else if (a->markup[0] == 0)
			ft_push(a, b);
		else
			ft_rotate(a, a->cur_size, 0);
		update_markup(a, m_head);
	}

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

}
