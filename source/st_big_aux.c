/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_big_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 20:05:25 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/02 13:13:57 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack_aux	*change_chuncks(t_stack_info *info, int *l, int *r, int *div)
{
	if (info->cont == *div)
	{
		sort_b (info, *l, *r, *div);
		*l -= *div;
		*r -= *div;
		info->cont = 0;
		if (*l < 0 && *r > *l)
		{
			*l = 0;
			*div = *r + 1;
		}
	}
	return (NULL);
}

void	set_chuncks(t_stack_info *info, int *l, int *r, int *div)
{
	if (*l == 0 && *div == 0 && *r == 0)
	{
		if (info->stack_len <= 20)
			*div = 5;
		else if (info->stack_len <= 100)
			*div = 30;
		else if (info->stack_len <= 500)
			*div = 35;
		else
			*div = 46;
		*r = info->stack_len - 1;
		*l = info->stack_len - *div;
	}
}

t_stack_aux	*set_aux(t_stack_info *info, int *l_bound, int *r_bound)
{
	t_stack_aux	*aux;

	aux = (t_stack_aux *)malloc(sizeof(t_stack_aux));
	if (!aux)
		ft_check_error(-1, "init aux stack", info);
	aux->head = info->head_a;
	aux->tail = (t_node *)ft_lstlast((t_list *)info->head_a);
	aux->hold_1 = search_in_range(*l_bound, *r_bound, aux->head, 1);
	aux->hold_2 = search_in_range(*l_bound, *r_bound, aux->tail, 2);
	aux->t1 = from_head(aux->head, aux->hold_1);
	aux->t2 = from_tail(aux->tail, aux->hold_2);
	return (aux);
}

static void	check_before_push(t_stack_info *info, t_node *node)
{
	int		put_max_on_top;
	t_node	*top;

	if (node->index != info->head_a->index + 1
		&& node->index != info->stack_len - 1)
	{
		top = search_element(node->index + 1, info->head_a, 1);
		put_max_on_top = tail_or_head(info, top, info->head_a);
		if (info->args == 1)
			run(info, "ra", put_max_on_top);
		else
			run(info, "rra", put_max_on_top);
	}
}

void	sort_b(t_stack_info *info, int min, int max, int div)
{
	static int	bigger;
	t_node		*node;
	int			times;

	if (!info->head_b)
		return ;
	if (bigger == 0 && info->head_b->next)
		bigger = max;
	node = search_element(bigger, info->head_b, 1);
	if (info->head_b == node)
		times = 0;
	else if (info->head_b->next == node)
		swap_b(info->head_b, info);
	else
	{
		times = tail_or_head(info, node, info->head_b);
		if (info->args == 1)
			run(info, "rb", times);
		else if (info->args == 2)
			run(info, "rrb", times);
	}
	check_before_push(info, info->head_b);
	push_a(info);
	bigger--;
	sort_b(info, min, max, div);
}
