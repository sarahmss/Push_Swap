/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:58:28 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/18 11:25:22 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_info	*info_s;

	if (argc <= 1)
	{
		ft_printf("Insert a list to be sorted: ./push_swap <int list> \n");
		exit (0);
	}
	info_s = init_stack_info(argc - 1);
	info_s->head_a = ft_create_a_stack(argc, argv, info_s);
	if (ft_check_sort(info_s->head_a))
		ft_check_error(2, "sorted list \n", info_s);
	else
	{
		ft_printf("Not sorted list\n");
		/*if (info_s->a_stack_len <= 5)
			ft_sort_small_stack();
		else
			ft_sort_big_stack();*/
	}
	return (0);
}
