/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searching.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:21:11 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/01 11:42:22 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
	Returns a pointer if the element is found in the list, otherwise returns null
	mod: 1 for search index
*/
t_node	*search_element(int data, t_node *head, int mod)
{
	t_node	*temp;

	temp = head;
	if (mod == 1)
	{
		while (temp != NULL)
		{
			if (temp->index == data)
				return (temp);
			temp = temp->next;
		}
	}
	else
	{
		while (temp != NULL)
		{
			if (temp->data == data)
				return (temp);
			temp = temp->next;
		}
	}
	return (NULL);
}

/*
	Returns a pointer if a element contained in a range is found in the list,
	otherwise returns null
	mod: 1 for search from head to tail
	mod: 2 for search from tail to head
*/
t_node	*search_in_range(int left, int right, t_node *node, int mod)
{
	t_node	*temp;

	temp = node;
	if (mod == 1)
	{
		while (temp != NULL)
		{
			if ((left <= temp->index) && (temp->index <= right))
				return (temp);
			temp = temp->next;
		}
	}
	if (mod == 2)
	{
		while (temp != NULL)
		{
			if ((left <= temp->index) && (temp->index <= right))
				return (temp);
			temp = temp->prev;
		}
	}
	return (NULL);
}

int	from_tail(t_node *tail, t_node *smallest)
{
	t_node		*temp;
	int			rra;

	rra = 1;
	temp = tail;
	if (tail->index == smallest->index)
		return (rra);
	while (temp->index != smallest->index)
	{
		temp = temp->prev;
		rra++;
	}
	return (rra);
}

int	from_head(t_node *head, t_node *smallest)
{
	t_node		*temp;
	int			ra;

	ra = 0;
	temp = head;
	if (head->index == smallest->index)
		return (0);
	while (temp->index != smallest->index)
	{
		temp = temp->next;
		ra++;
	}
	return (ra);
}
/*
	given a node returns the least amount of operations to place it on top
*/

int	tail_or_head(t_stack_info *info, t_node *top, t_node *head)
{
	t_node		*node;
	int			ra;
	int			rra;

	node = top;
	info->temp = (t_node *)ft_lstlast((t_list *)head);
	ra = from_head(head, node);
	rra = from_tail(info->temp, node);
	if (ra < rra)
	{
		info->args = 1;
		return (ra);
	}
	else
	{
		info->args = 2;
		return (rra);
	}
}
