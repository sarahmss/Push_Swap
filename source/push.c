/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:39:22 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/23 16:12:31 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
	take the first element at the top of b and put it at the top of a.
	Do nothing if b is empty
*/
void	push_a(t_stack_info *info)
{
	if (info->head_b)
	{
		info->head_a = ft_insert_at_head(info->head_b->data, info->head_a);
		stack_del(&info->head_b, info->head_b);
	}
	write(1, "pb\n", 3);
}

/*
	take the first element at the top of a and put it at the top of b.
	Do nothing if b is empty
*/
void	push_b(t_stack_info *info)
{
	if (info->head_a)
	{
		info->head_b = ft_insert_at_head(info->head_a->data, info->head_b);
		stack_del(&info->head_a, info->head_a);
	}
	write(1, "pb\n", 3);
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
