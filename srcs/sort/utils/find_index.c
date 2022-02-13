int	find_index(int num, int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (num == arr[i])
			return (i);
		i++;
	}
	return (i);
}
