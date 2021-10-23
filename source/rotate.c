/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:39:22 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/23 12:57:32 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
	shift up all elements of stack_a by 1.
	The first element becomes the last one
*/
void	rotate_a(t_node **head_a)
{
	t_node	*head;
	t_node	*tail;

	if (*head_a == NULL)
		return ;
	head = *head_a;
	tail = (t_node *)ft_lstlast((t_list *)head);
	head->next->prev = NULL;
	*head_a = head->next;
	tail->next = head;
	head->prev = tail;
	head->next = NULL;
	write(1, "ra\n", 3);
}

/*
	rotate b - shift up all elements of stack_b by 1.
	The first element becomes the last one
*/
void	rotate_b(t_node **head_b)
{
	t_node	*head;
	t_node	*tail;

	if (*head_b == NULL)
		return ;
	head = *head_b;
	tail = (t_node *)ft_lstlast((t_list *)head);
	head->next->prev = NULL;
	*head_b = head->next;
	tail->next = head;
	head->prev = tail;
	head->next = NULL;
	write(1, "rb\n", 3);
}

/*
	ra and rb at the same time
*/
void	rotate_a_b(t_node **head_b, t_node **head_a)
{
	rotate_a(head_a);
	rotate_b(head_b);
	write(1, "rr\n", 3);
}
