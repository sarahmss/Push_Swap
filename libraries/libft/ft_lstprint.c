/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:59:53 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/25 19:16:15 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

void	ft_print_list(t_nodel *head)
{
	t_nodel	*temp;

	temp = head;
	while (temp->next != NULL)
	{
		ft_printf("elem[%d]: %d \n", temp->index, temp->data);
		temp = temp->next;

	}
	ft_printf("elem[%d]: %d \n", temp->index, temp->data);
	ft_printf("-----a-----\n");
}
