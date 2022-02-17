/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 00:18:23 by jyolando          #+#    #+#             */
/*   Updated: 2022/02/18 00:18:25 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
