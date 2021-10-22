/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:39:22 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/22 19:23:55 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
	take the first element at the top of b and put it at the top of a.
	Do nothing if b is empty
*/
char	*push_a(t_node **head_a, t_node *head_b)
{
	if (head_b)
	{
		*head_a = ft_insert_at_head(head_b->data, *head_a);
		stack_del(&head_b, head_b);
	}
	return ("pb\n");
}

/*
	take the first element at the top of b and put it at the top of a.
	Do nothing if b is empty
*/
char	*push_b(t_node **head_b, t_node *head_a)
{
	if (head_a)
	{
		*head_b = ft_insert_at_head(head_a->data, *head_b);
		stack_del(&head_a, head_a);
	}
	return ("pb\n");
}

/*
	Delete a node del in the stack
*/
void	stack_del(t_node **head, t_node *del)
{
	if (*head == NULL || del == NULL)
		return ;
	if (*head == del)
		*head = del->next;
	if (del->next != NULL)
		del->next->prev = del->prev;
	if (del->prev != NULL)
		del->prev->next = del->next;
	free(del);
	return ;
}
