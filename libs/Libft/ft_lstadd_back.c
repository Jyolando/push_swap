/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 19:14:18 by jyolando          #+#    #+#             */
/*   Updated: 2021/10/04 20:03:44 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *nlist)
{
	t_list	*nlst;

	if (!nlist)
		return ;
	else if (!*lst)
	{
		*lst = nlist;
		return ;
	}
	nlst = *lst;
	nlst = ft_lstlast(nlst);
	nlst->next = nlist;
}
