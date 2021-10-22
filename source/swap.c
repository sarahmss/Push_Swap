/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:26:27 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/22 19:20:25 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
	swap the first 2 elements at the top of stack_a
*/
char	*swap_a(t_node *head_a)
{
	if ((head_a != NULL) && (head_a->next != NULL))
		ft_swap (head_a, head_a->next);
	return ("sa\n");
}

/*
	swap the first 2 elements at the top of stack_b
*/
char	*swap_b(t_node *head_b)
{
	if ((head_b != NULL) && (head_b->next != NULL))
		ft_swap (head_b, head_b->next);
	return ("sb\n");
}

/*
	swap the first 2 elements at the top of stack_a and stack_b
*/
char	*swap_a_b(t_node *head_a, t_node *head_b)
{
	swap_a (head_a);
	swap_b (head_b);
	return ("ss\n");
}
