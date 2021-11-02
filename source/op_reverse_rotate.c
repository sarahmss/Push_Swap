/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:39:22 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/01 20:07:04 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
	reverse rotate a - shift down all elements of stack_a by 1.
	The last element becomes the first one
*/
void	reverse_rotate_a(t_node **head_a, t_stack_info *info)
{
	t_node	*head;
	t_node	*tail;

	if (*head_a == NULL)
		return ;
	head = *head_a;
	tail = (t_node *)ft_lstlast((t_list *)head);
	head->prev = tail;
	tail->next = head;
	tail->prev->next = NULL;
	tail->prev = NULL;
	*head_a = tail;
	create_operations(info, "rra");
	info->op++;
}
/*
	reverse rotate b - shift down all elements of stack_b by 1.
	The last element becomes the first one
*/

void	reverse_rotate_b(t_node **head_b, t_stack_info *info)
{
	t_node	*head;
	t_node	*tail;

	if (*head_b == NULL)
		return ;
	head = *head_b;
	tail = (t_node *)ft_lstlast((t_list *)head);
	head->prev = tail;
	tail->next = head;
	tail->prev->next = NULL;
	tail->prev = NULL;
	*head_b = tail;
	create_operations(info, "rrb");
	info->op++;
}

void	reverse_rotate_a_b(t_node **head_a, t_node **head_b, t_stack_info *inf)
{
	reverse_rotate_a(head_a, inf);
	reverse_rotate_b(head_b, inf);
	create_operations(inf, "rrr");
}
