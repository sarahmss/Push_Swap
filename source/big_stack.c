/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 09:40:38 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/30 14:03:05 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ra_or_rra(t_stack_info *info, int *l_bound, int *r_bound, int *div)
{
	t_stack_aux	*aux;


	aux = set_aux(info, l_bound, r_bound);
	if (((aux->t1 == aux->t2) && (aux->hold_2->index > aux->hold_1->index))
		|| (aux->t1 < aux->t2))
		run(info, "ra", aux->t1);
	else if (((aux->t1 == aux->t2) && (aux->hold_1->index > aux->hold_2->index))
		|| (aux->t2 < aux->t1))
		run(info, "rra", aux->t2);
	push_b(info);
	info->cont++;
	change_chuncks(info, l_bound, r_bound, div);
	free(aux);
}

static void	sa_or_pa(t_stack_info *info, int *l_bound, int *r_bound, int *div)
{
	int	sa;

	sa = info->head_a->next->index;
	if ((*l_bound <= info->head_a->index) && (info->head_a->index <= *r_bound))
	{
		push_b(info);
		info->cont++;
	}
	else if ((*l_bound <= sa) && (sa <= *r_bound))
	{
		swap_a(info->head_a, info);
		push_b(info);
		info->cont++;
	}
	change_chuncks(info, l_bound, r_bound, div);
}

void	sort_big_stack(t_stack_info *info)
{
	static int	left_bound;
	static int	right_bound;
	static int	div;
	int			len;

	len = ft_lstsize((t_list *) info->head_a);
	if (ft_check_sort(info->head_a) && len == info->stack_len)
		return ;
	set_chuncks(info, &left_bound, &right_bound, &div);
	sa_or_pa(info, &left_bound, &right_bound, &div);
 	ra_or_rra(info, &left_bound, &right_bound, &div);
	sort_big_stack(info);
}
