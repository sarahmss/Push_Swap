/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:56:28 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/18 11:39:45 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*ft_create_a_stack(int len_s, char **str_stack, t_stack_info *info_s)
{
	int		i;
	int		temp_num;
	t_node	*head_a;

	head_a = NULL;
	i = 1;
	while (i < len_s)
	{
		temp_num = ft_atoi(str_stack[i]);
		if (ft_strisalnum(str_stack[i]))
		{
			if (i == 1)
			{
				head_a = ft_insert_at_head(temp_num, head_a);
				info_s->head_a = head_a;
			}
			else if (!search_element(temp_num, head_a))
				ft_insert_at_foot(temp_num, head_a);
		}
		if (!ft_strisalnum(str_stack[i]) && !search_element(temp_num, head_a))
			ft_check_error(-1, "\0", info_s);
		i++;
	}
	return (head_a);
}

int	ft_check_sort(t_node *stack)
{
	if (stack != NULL)
	{
		while (stack->next != NULL)
		{
			if (stack->data > stack->next->data)
				return (0);
			stack = stack->next;
		}
	}
	return (1);
}
