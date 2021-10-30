/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 20:05:25 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/29 20:43:51 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void check_before_push(t_stack_info *info, t_node *node)
{
	int		put_max_on_top;
	t_node	*top;

	if (node->index != info->head_a->index + 1)
	{
		top = search_element(node->index + 1 , info->head_a, 1);
		put_max_on_top = tail_or_head(info, top, info->head_a);
		if (info->args == 1)
			run(info, "ra", put_max_on_top);
		else
			run(info, "rra", put_max_on_top);
	}
}
void	sort_b(t_stack_info *info, int min, int max, int op)
{
	static int	bigger;
	t_node		*node;
	int			rb;
	int			rrb;

	if (!info->head_b)
		return ;
	if ((bigger == 0 && info->head_b->next) || bigger == min - 21)
		bigger = max;
	node = search_element(bigger, info->head_b, 1);
	if (info->head_b->next == node)
		swap_b(info->head_b, info);
	else
	{
		info->temp = (t_node *)ft_lstlast((t_list *)info->head_b);
		rb = from_head(info->head_b, node);
		rrb = from_tail(info->temp, node);
		if (rb < rrb && info->head_b->next)
			run(info, "rb", rb);
		else if(info->head_b->next)
			run(info, "rrb", rrb);
	}
	if (op > 0)
		check_before_push(info, info->head_b);
	push_a(info);
	bigger--;
	sort_b(info, min, max, op);
}
