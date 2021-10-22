/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:58:28 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/22 19:20:51 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
	Swap data stored in A and B
*/
void	ft_swap(t_node *A, t_node *B)
{
	int	temp;

	if (A != B)
	{
		temp = A->data;
		A->data = B->data;
		B->data = temp;
	}
}

t_node	*ft_partition(t_node *head, t_node *tail)
{
	int		pivot;
	t_node	*i;
	t_node	*j;

	j = head;
	pivot = tail->data;
	i = head->prev;
	while (j != tail)
	{
		if (j->data <= pivot)
		{
			if (i == NULL)
				i = head;
			else
				i = i->next;
			ft_swap(i, j);
		}
		j = j->next;
	}
	if (i == NULL)
		i = head;
	else
		i = i->next;
	ft_swap(i, j);
	return (i);
}

void	quick_sort(t_node *head, t_node *tail)
{
	t_node	*partition;

	if ((head != NULL) && (tail != NULL)
		&& (tail != head) && (tail != head->next))
	{
		partition = ft_partition(head, tail);
		quickSort(head, partition->prev);
		quickSort(partition->next, tail);
	}
}
