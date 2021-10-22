/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:58:28 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/21 19:29:16 by smodesto         ###   ########.fr       */
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
		ft_print_list((t_nodel *)info->head_a);
		info->tail_a = (t_node *)ft_lstlast((t_list *)info->head_a);
		quickSort(info->head_a, info->tail_a);
		ft_print_list((t_nodel *)info->head_a);
		/*if (info->stack_len <= 5)
			ft_sort_small_stack();
		else
			ft_sort_big_stack();*/
	}
	return (0);
}
