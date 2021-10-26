/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 19:27:48 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/26 09:58:55 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
	Push elements back to a ordering them
*/
static void	push_back(t_stack_info *info)
{
	if (!info->head_b)
		return ;
	if (info->head_b->next && info->head_b->index > info->head_b->next->index)
		swap_b (info->head_b, info);
	push_a (info);
	if (info->head_a->index > info->head_a->next->index)
		swap_a(info->head_a, info);
	push_back (info);
}

/*
	hold temporarily stack_a's smaller elements in b
*/
static void	push_forward(t_stack_info	*info)
{
	int	len;

	len = ft_lstsize((t_list *) info->head_a);
	if (len == 3)
		return ;
	if (info->head_a->index == 0 || info->head_a->index == 1)
		push_b(info);
	else
		rotate_a(&info->head_a, info);
	push_forward (info);
}

/*
	cover 6! possibilities of sorting a len 3 stack
*/
static void	sort_len3_stack(t_stack_info *info)
{
	t_worm	*w;

	info->w = init_worm(info, info->w);
	w = info->w;
	if ((w->head > w->body) && (w->body < w->tail) && (w->tail > w->head))
		swap_a(info->head_a, info);
	else if ((w->head > w->body) && (w->body > w->tail) && (w->tail < w->head))
	{
		swap_a(info->head_a, info);
		reverse_rotate_a(&info->head_a, info);
	}
	else if ((w->head > w->body) && (w->body < w->tail) && (w->tail < w->head))
		rotate_a(&info->head_a, info);
	else if ((w->head < w->body) && (w->body > w->tail) && (w->tail > w->head))
	{
		swap_a(info->head_a, info);
		rotate_a(&info->head_a, info);
	}
	else if ((w->head < w->body) && (w->body > w->tail) && (w->tail < w->head))
		reverse_rotate_a(&info->head_a, info);
	push_back(info);
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
		swap_a(info->head_a, info);
		return ;
	}
	if (len == 3)
		sort_len3_stack(info);
	else
		push_forward(info);
	sort_small_stack(info);
}
