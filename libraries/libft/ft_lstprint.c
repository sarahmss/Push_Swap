/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:59:53 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/23 13:03:14 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

void	ft_print_list(t_nodel *head)
{
	t_nodel	*temp;
	int		i;

	i = 0;
	temp = head;
	while (temp->next != NULL)
	{
		ft_printf("elem[%d]: %d \n", i, temp->data);
		temp = temp->next;
		i++;
	}
	ft_printf("elem[%d]: %d \n", i, temp->data);
	ft_printf("-----a-----\n");
}
