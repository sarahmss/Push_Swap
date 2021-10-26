/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:39:22 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/26 09:47:58 by smodesto         ###   ########.fr       */
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
	write(1, "rra\n", 4);
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
	write(1, "rrb\n", 4);
	info->op++;
}

void	reverse_rotate_a_b(t_node **head_a, t_node **head_b, t_stack_info *inf)
{
	reverse_rotate_a(head_a, inf);
	reverse_rotate_b(head_b, inf);
	write(1, "rrr\n", 4);
}
