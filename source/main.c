/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:58:28 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/01 21:23:37 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_info	*info;

	if (argc == 1)
		return (0);
	info = init_stack_info();
	info->args_list = args_list(info, argv, argc);
	ft_create_a_stack(info);
	if (ft_check_sort(info->head_a))
		ft_check_error(0, "\0", info);
	else
	{
		ft_put_index(info);
		if (info->stack_len <= 5)
			sort_small_stack(info);
		else
			sort_big_stack(info);
		optimize_operations(info->inst);
		ft_print_op(info->inst);
	}
	before_living(info);
	return (0);
}
