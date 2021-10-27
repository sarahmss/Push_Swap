/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 09:40:38 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/27 19:50:17 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack_aux *	set_aux(t_stack_info *info, int *left_bound, int *right_bound)
{
	static int	cont;
	t_stack_aux	*aux;

	aux = (t_stack_aux *)malloc(sizeof(t_stack_aux));
	if (!aux)
		ft_check_error(-1, "init aux stack", info);
	aux->head = info->head_a;
	aux->tail = (t_node *)ft_lstlast((t_list *)info->head_a);
	aux->hold_1 = search_in_range(*left_bound, *right_bound, aux->head, 1);
	aux->hold_2 = search_in_range(*left_bound, *right_bound, aux->tail, 2);
	aux->t1 = from_head(aux->head, aux->hold_1);
	aux->t2 = from_tail(aux->tail, aux->hold_2);
	cont++;
	if (cont == 20)
	{
		*left_bound += 20;
		*right_bound += 20;
		cont = 0;
	}
	return (aux);
}

static int	ra_or_rra(t_stack_info *info)
{
	static int	left_bound;
	static int	right_bound;
	t_stack_aux	*aux;
	int			times;

	if (left_bound == 0)
		right_bound = 19;
	aux = set_aux(info, &left_bound, &right_bound);
	if (aux->t1 == aux->t2)
	{
		if (aux->hold_1->index < aux->hold_2->index)
			info->args = 1;
		else
			info->args = 2;
		times = aux->t1;
	}
	else if (aux->t1 < aux->t2)
	{
		info->args = 1;
		times = aux->t1;
	}
	else
	{
		info->args = 2;
		times = aux->t2;
	}
	free(aux);
	return (times);
}

static void	big_recursive_stack(t_stack_info *info)
{
	int			len;
	int			times;

	len = ft_lstsize((t_list *) info->head_b);
	if (info->stack_len == len)
		return ;
	if (info->head_a->next)
		times = ra_or_rra(info);
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
//	run(info, "pa", info->stack_len);
}
