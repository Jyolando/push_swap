#include "../../../includes/push_swap.h"

int	*copy_sa_arr(int *tab, int size)
{
	int	i;
	int	*arr;

	i = 2;
	arr = (int *)malloc(sizeof(int) * size);
	if (arr == NULL)
		return (NULL);
	arr[0] = tab[1];
	arr[1] = tab[0];
	while (i < size)
	{
		arr[i] = tab[i];
		i++;
	}
	return (arr);
}

void	update_markup(t_stack *a, int m_head)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	temp = m_head;
	while (a->tab[i] != m_head)
		i++;
	while (j < a->cur_size)
	{
		if (a->tab[i] < temp)
			a->markup[i] = 0;
		else
		{
			temp = a->tab[i];
			a->markup[i] = 1;
		}
		i++;
		if (i == a->cur_size)
			i = 0;
		j++;
	}
}
