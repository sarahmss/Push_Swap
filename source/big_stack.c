/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 09:40:38 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/26 09:59:03 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_big_stack(t_stack_info *info)
{
	int	len;

	len = ft_lstsize((t_list *) info->head_a);
	if ((ft_check_sort(info->head_a)) && (info->stack_len == len))
		return ;
}
