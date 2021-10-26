/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 11:38:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/26 09:55:59 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	run_sup(t_stack_info *info, char *operation)
{
	if (ft_strncmp(operation, "pa", 2) == 0)
		push_a(info);
	else if (ft_strncmp(operation, "pb", 2) == 0)
		push_b(info);
	else if (ft_strncmp(operation, "sa", 2) == 0)
		swap_a(info->head_a, info);
	else if (ft_strncmp(operation, "sb", 2) == 0)
		swap_b(info->head_b, info);
	else if (ft_strncmp(operation, "ss", 2) == 0)
		swap_a_b(info->head_a, info->head_b, info);
	else if (ft_strncmp(operation, "ra", 2) == 0)
		rotate_a(&info->head_a, info);
	else if (ft_strncmp(operation, "rb", 2) == 0)
		rotate_b(&info->head_b, info);
	else if (ft_strncmp(operation, "rr", 2) == 0)
		rotate_a_b(&info->head_a, &info->head_b, info);
	else if (ft_strncmp(operation, "rra", 3) == 0)
		reverse_rotate_a(&info->head_a, info);
	else if (ft_strncmp(operation, "rrb", 3) == 0)
		reverse_rotate_b(&info->head_b, info);
	else if (ft_strncmp(operation, "rrr", 3) == 0)
		reverse_rotate_a_b(&info->head_a, &info->head_b, info);
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
