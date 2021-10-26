/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:26:27 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/26 09:51:32 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
	swap the first 2 elements at the top of stack_a
*/
void	swap_a(t_node *head_a, t_stack_info *info)
{
	if ((head_a != NULL) && (head_a->next != NULL))
		ft_swap (head_a, head_a->next);
	write(1, "sa\n", 3);
	info->op++;
}

/*
	swap the first 2 elements at the top of stack_b
*/
void	swap_b(t_node *head_b, t_stack_info *info)
{
	if ((head_b != NULL) && (head_b->next != NULL))
		ft_swap (head_b, head_b->next);
	write(1, "sb\n", 3);
	info->op++;
}

/*
	swap the first 2 elements at the top of stack_a and stack_b
*/
void	swap_a_b(t_node *head_a, t_node *head_b, t_stack_info *info)
{
	swap_a (head_a, info);
	swap_b (head_b, info);
	write(1, "ss\n", 3);
}
