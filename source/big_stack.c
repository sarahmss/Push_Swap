/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 09:40:38 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/26 23:38:18 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	from_tail(t_node *tail, t_node *smallest)
{
	t_node		*temp;
	int			rra;

	rra = 1;
	temp = tail;
	if (tail->index == smallest->index)
		return (rra);
	while (temp->index != smallest->index)
	{
		temp = temp->prev;
		rra++;
	}
	return (rra);
}

static int from_head(t_node *head, t_node *smallest)
{
	t_node		*temp;
	int			ra;

	ra = 0;
	temp = head;
	if (head->index == smallest->index)
		return (0);
	while (temp->index != smallest->index)
	{
		temp = temp->next;
		ra++;
	}
	return (ra);
}

static int	tail_or_head(t_stack_info *info)
{
	static int	smallest;
	t_node		*node;
	int			ra;
	int			rra;

	node = search_element(smallest, info->head_a, 1);
	info->temp = (t_node *)ft_lstlast((t_list *)info->head_a);
	ra = from_head(info->head_a, node);
	rra = from_tail(info->temp, node);
	smallest++;
	if (ra < rra)
	{
		info->args = 1;
		return (ra);
	}
	else
	{
		info->args = 2;
		return (rra);
	}
}


static void	big_recursive_stack(t_stack_info *info)
{
	int			len;
	int			times;

	len = ft_lstsize((t_list *) info->head_b);
	if (info->stack_len == len)
		return ;
	if (info->head_a->next)
		times = tail_or_head(info);
	if (info->args == 1 && info->head_a->next)
		run(info, "ra", times);
	if (info->args == 2 && info->head_a->next)
		run(info, "rra", times);
	push_b(info);
	big_recursive_stack(info);
}

void	sort_big_stack(t_stack_info *info)
{
	big_recursive_stack(info);
	run(info, "pa", info->stack_len);
}
