/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 19:27:48 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/25 11:59:19 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
/*
static	void push_back(t_stack_info *info)
{
	if (!info->head_b)
		return ;
}
*/
/*
	cover 6! possibilities of sorting a len 3 stack
*/
static void	sort_len3_stack(t_stack_info *info)
{
	t_worm	*w;

	info->w = init_worm(info, info->w);
	w = info->w;
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
}

/*
	Sort stack <= 5
*/
void	sort_small_stack(t_stack_info *info)
{
	int	len;

	len = ft_lstsize((t_list *) info->head_a);
	if ((ft_check_sort(info->head_a)) && (info->stack_len == len))
		return ;
	if (len == 2)
	{
		swap_a(info->head_a);
		return ;
	}
	if (len == 3)
		sort_len3_stack(info);
/*	else if (info->stack_len == 4)
		sort_len4_stack(info);
	else if (info->stack_len == 5)
		sort_len5_stack(info);*/
}
