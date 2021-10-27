/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:58:28 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/26 15:15:58 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
	Swap data stored in A and B
*/
void	ft_swap(t_node *A, t_node *B)
{
	int	temp;
	int	temp_i;

	if (A != B)
	{
		temp = A->data;
		temp_i = A->index;
		A->data = B->data;
		A->index = B->index;
		B->data = temp;
		B->index = temp_i;
	}
}

/*
	j: iterator, from head to tail
*/
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
		if (j->data < pivot)
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

	if ((tail != NULL) && (tail != head) && (head != tail->next))
	{
		partition = ft_partition(head, tail);
		quick_sort(head, partition->prev);
		quick_sort(partition->next, tail);
	}
}

t_node	*lstcopy(t_node *src)
{
	t_node	*dest;
	t_node	*temp;

	dest = NULL;
	temp = src->next;
	dest = ft_insert_at_head(src->data, dest);
	while (temp->next)
	{
		ft_insert_at_foot(temp->data, dest);
		temp = temp->next;
	}
	ft_insert_at_foot(temp->data, dest);
	return (dest);
}

void	ft_put_index(t_stack_info *info)
{
	t_node	*sorted;
	t_node	*temp_ind;
	t_node	*temp_sort;
	int		i;

	sorted = lstcopy(info->head_a);
	temp_sort = (t_node *)ft_lstdlast((t_nodel *)sorted);
	quick_sort(sorted, temp_sort);
	i = 0;
	temp_sort = sorted;
	while (i < info->stack_len)
	{
		temp_ind = search_element(temp_sort->data, info->head_a, 0);
		temp_ind->index = i;
		temp_sort = temp_sort->next;
		i++;
	}
	ft_free_list(sorted);
}
