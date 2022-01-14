/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_atoi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:54:16 by                   #+#    #+#             */
/*   Updated: 2022/01/14 22:05:29 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_parse_atoi(const char *s, int *res)
{
	int i;
	int neg;
	long temp;

	i = 0;
	neg = 1;
	temp = 0;
	if (s[i] == '-' || s[i] == '+')
		if (s[i++] == '-')
			neg = -1;
	if (!ft_isdigit(s[i]))
		return (0);
	while (ft_isdigit(s[i]))
	{
		temp = temp * 10 + s[i] - 48;
		i++;
	}
	temp *= neg;
	if (s[i] != '\0' || temp > 2147483647
		|| temp < -2147483648)
		return (0);
	*res = (int)temp;
	return (1);
}