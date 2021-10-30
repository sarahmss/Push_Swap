/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 09:40:38 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/29 23:45:51 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_stack_aux	*chuncks(t_stack_aux *aux, int *l, int *r, int *cont)
{
	if (*l == 0 && *r != 19)
	{
		*r = aux->info->stack_len - 1;
		*l = aux->info->stack_len - 20;
		return (NULL);
	}
	if (*cont == 20)
	{
		if (aux->t1 < aux->t2)
			run(aux->info, "ra", aux->t1);
		else
			run(aux->info, "rra", aux->t2);
		push_b(aux->info);
		sort_b (aux->info, *l, *r);
		*l -= 20;
		*r -= 20;
		*cont = 0;
		free(aux);
		return (NULL);
	}
}

t_stack_aux	*set_aux(t_stack_info *info)
{
	static int	cont;
	static int	left_bound;
	static int	right_bound;
	t_stack_aux	*aux;

	aux = (t_stack_aux *)malloc(sizeof(t_stack_aux));
	if (!aux)
		ft_check_error(-1, "init aux stack", info);
	aux->info = info;
	aux->head = info->head_a;
	chuncks(aux, &left_bound, &right_bound, &cont);
	aux->tail = (t_node *)ft_lstlast((t_list *)info->head_a);
	aux->hold_1 = search_in_range(left_bound, right_bound, aux->head, 1);
	aux->hold_2 = search_in_range(left_bound, right_bound, aux->tail, 2);
	aux->t1 = from_head(aux->head, aux->hold_1);
	aux->t2 = from_tail(aux->tail, aux->hold_2);
	cont++;
	if (chuncks(aux, &left_bound, &right_bound, &cont) == NULL)
		return (NULL);
	return (aux);
}

static int	ra_or_rra(t_stack_info *info)
{
	t_stack_aux	*aux;
	int			times;

	aux = set_aux(info);
	if (aux == NULL)
		return (-1);
	if (((aux->t1 == aux->t2) && (aux->hold_2->index > aux->hold_1->index))
		|| (aux->t1 < aux->t2))
	{
		info->args = 1;
		times = aux->t1;
	}
	else if (((aux->t1 == aux->t2) && (aux->hold_1->index > aux->hold_2->index))
		|| (aux->t2 < aux->t1))
	{
		info->args = 2;
		times = aux->t2;
	}
	free(aux);
	return (times);
}

void	sort_big_stack(t_stack_info *info)
{
	int			times;
	int			len;

	len = ft_lstsize((t_list *)info->head_a);
	if (ft_check_sort(info->head_a))
		return ;
	if (info->head_a->next)
		times = ra_or_rra(info);
	if (info->args == 1 && info->head_a->next)
		run(info, "ra", times);
	if (info->args == 2 && info->head_a->next)
		run(info, "rra", times);
	if (times != -1)
		push_b(info);
	sort_big_stack(info);
}
