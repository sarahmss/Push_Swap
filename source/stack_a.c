/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:56:28 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/17 13:01:22 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*ft_create_a_stack(int stack_len, char **str_stack)
{
	int		i;
	int		temp_num;
	t_node	*head_a;

	i = 1;
	head_a = NULL;
	while (i < stack_len)
	{
		if (ft_strisalnum(str_stack[i]))
		{
			temp_num = ft_atoi(str_stack[i]);
			if (i == 1)
				head_a = ft_insert_at_head(temp_num, head_a);
			if (ft_search_elements(temp_num, head_a))
			{
				ft_free_list(head_a);
				ft_check_error(-1, "\0");
			}
			else
				ft_insert_at_foot(temp_num, head_a);
		}
		else
			ft_check_error(-1, "\0");
		i++;
	}
	return (head_a);
}

int	ft_check_sort(t_node *stack)
{
	
}
