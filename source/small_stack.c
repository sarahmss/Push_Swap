/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 19:27:48 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/23 17:54:09 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
	cover 6! possibilities of sorting a len 3 stack
*/
static t_worm	*sort_len3_stack(t_stack_info *info)
{
	t_worm	*w;

	w = NULL;
	w = init_worm(info->head_a->data,
			info->head_a->next->data, info->head_a->next->next->data, w);
	if ((w->head > w->body) && (w->body < w->tail) && (w->tail > w->head))
		swap_a(info->head_a);
	else if ((w->head > w->body) && (w->body > w->tail) && (w->tail < w->head))
	{
		swap_a(info->head_a);
		reverse_rotate_a(&info->head_a);
	}
	else if ((w->head > w->body) && (w->body < w->tail) && (w->tail < w->head))
		rotate_a(&info->head_a);
	else if ((w->head < w->body) && (w->body > w->tail) && (w->tail > w->head))
	{
		swap_a(info->head_a);
		rotate_a(&info->head_a);
	}
	else if ((w->head < w->body) && (w->body > w->tail) && (w->tail < w->head))
		reverse_rotate_a(&info->head_a);
	free (w);
	w = NULL;
	return (init_worm(info->head_a->data,
			info->head_a->next->data, info->head_a->next->next->data, w));
}

static void	sort_len4_stack(t_stack_info *info)
{
	int		head_b;
	t_worm	*w;

	push_b(info);
	head_b = info->head_b->data;
	w = sort_len3_stack(info);
	if ((head_b < w->head) || (head_b < w->body))
		push_a(info);
	if (head_b < w->body)
		swap_a(info->head_a);
	else if ((head_b > w->body) && (head_b < w->tail))
	{
		run(info, "pb", 2);
		reverse_rotate_b(&info->head_b);
		run(info, "pa", 3);
	}
	else if ((head_b > w->body) && (head_b > w->tail))
	{
		run(info, "pb", 3);
		reverse_rotate_b(&info->head_b);
		run(info, "pa", 4);
	}
	free (w);
}

static void	sort_len5_stack(t_stack_info *info)
{
	t_worm	*w;

	push_b(info);
	push_b(info);
	w = sort_len3_stack(info);
	push_a(info);
	free (w);
}

/*
	Sort stack <= 5
*/
void	sort_small_stack(t_stack_info *info)
{
	t_worm	*w;

	if ((info->stack_len == 0) || (info->stack_len == 1))
		return ;
	else if (info->stack_len == 2)
	{
		if (!ft_check_sort (info->head_a))
			swap_a(info->head_a);
		else
			return ;
	}
	else if (info->stack_len == 3)
	{
		w = sort_len3_stack(info);
		free (w);
	}
	else if (info->stack_len == 4)
		sort_len4_stack(info);
	else if (info->stack_len == 5)
		sort_len5_stack(info);
}
