/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:39:22 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/22 19:22:02 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
	shift up all elements of stack_a by 1.
	The first element becomes the last one
*/
char	*rotate_a(t_node **head_a)
{
	t_node	*head;
	t_node	*tail;

	if (*head_a == NULL)
		return ("\0");
	head = *head_a;
	tail = (t_node *)ft_lstlast((t_list *)head);
	head->next->prev = NULL;
	*head_a = head->next;
	tail->next = head;
	head->prev = tail;
	head->next = NULL;
	return ("ra\n");
}

/*
	rotate b - shift up all elements of stack_b by 1.
	The first element becomes the last one
*/
char	*rotate_b(t_node **head_b)
{
	t_node	*head;
	t_node	*tail;

	if (*head_b == NULL)
		return ("\0");
	head = *head_b;
	tail = (t_node *)ft_lstlast((t_list *)head);
	head->next->prev = NULL;
	*head_b = head->next;
	tail->next = head;
	head->prev = tail;
	head->next = NULL;
	return ("rb\n");
}

/*
	ra and rb at the same time
*/
char	*rotate_a_b(t_node **head_b, t_node **head_a)
{
	rotate_a(head_a);
	rotate_b(head_b);
	return ("rr\n");
}
