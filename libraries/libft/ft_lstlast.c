/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 08:41:22 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/21 19:22:50 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;

	current = lst;
	if (current == NULL)
		return (0);
	while (current->next != NULL)
		current = current->next;
	return (current);
}

t_nodel	*ft_lstdlast(t_nodel *lst)
{
	t_nodel	*current;

	current = lst;
	if (current == NULL)
		return (0);
	while (current->next != NULL)
		current = current->next;
	return (current);
}
