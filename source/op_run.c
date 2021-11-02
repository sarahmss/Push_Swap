/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 11:38:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/01 20:58:18 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_print_op(t_operations *operations)
{
	t_operations	*temp;

	temp = operations;
	while (temp->next != NULL)
	{
		ft_printf("%s\n", temp->op);
		temp = temp->next;
	}
	ft_printf("%s\n", temp->op);
}

static void	run_sup(t_stack_info *info, char *operation)
{
	if (ft_strcmp(operation, "pa"))
		push_a(info);
	else if (ft_strcmp(operation, "pb"))
		push_b(info);
	else if (ft_strcmp(operation, "sa"))
		swap_a(info->head_a, info);
	else if (ft_strcmp(operation, "sb"))
		swap_b(info->head_b, info);
	else if (ft_strcmp(operation, "ss"))
		swap_a_b(info->head_a, info->head_b, info);
	else if (ft_strcmp(operation, "rra"))
		reverse_rotate_a(&info->head_a, info);
	else if (ft_strcmp(operation, "rrb"))
		reverse_rotate_b(&info->head_b, info);
	else if (ft_strcmp(operation, "rrr"))
		reverse_rotate_a_b(&info->head_a, &info->head_b, info);
	else if (ft_strcmp(operation, "ra"))
		rotate_a(&info->head_a, info);
	else if (ft_strcmp(operation, "rb"))
		rotate_b(&info->head_b, info);
	else if (ft_strcmp(operation, "rr"))
		rotate_a_b(&info->head_a, &info->head_b, info);
}

/*
	runs the operation i times
*/
void	run(t_stack_info *info, char *operation, int times)
{
	int	i;

	i = 0;
	while (i < times)
	{
		run_sup(info, operation);
		i++;
	}
}
