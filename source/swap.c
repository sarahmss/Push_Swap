/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:26:27 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/23 12:19:57 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
	swap the first 2 elements at the top of stack_a
*/
void	swap_a(t_node *head_a)
{
	if ((head_a != NULL) && (head_a->next != NULL))
		ft_swap (head_a, head_a->next);
	write(1, "sa\n", 3);
}

/*
	swap the first 2 elements at the top of stack_b
*/
void	swap_b(t_node *head_b)
{
	if ((head_b != NULL) && (head_b->next != NULL))
		ft_swap (head_b, head_b->next);
	write(1, "sb\n", 3);
}

/*
	swap the first 2 elements at the top of stack_a and stack_b
*/
void	swap_a_b(t_node *head_a, t_node *head_b)
{
	swap_a (head_a);
	swap_b (head_b);
	write(1, "ss\n", 3);
}
