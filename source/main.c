/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:58:28 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/29 20:50:59 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_info	*info;

	if (argc < 2)
	{
		ft_printf("Insert a list to be sorted: ./push_swap <int list> \n");
		exit (0);
	}
	info = init_stack_info();
	info->args_list = args_list(info, argv, argc);
	ft_create_a_stack(info);
	if (ft_check_sort(info->head_a))
		ft_check_error(2, "sorted list \n", info);
	else
	{
		ft_put_index(info);
		if (info->stack_len <= 5)
			sort_small_stack(info);
		else
			sort_big_stack(info);
		ft_printf("Total operations: %d\n", info->op);
	}
	before_living(info);
	return (0);
}
