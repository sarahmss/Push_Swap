/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:23:42 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/02 19:14:07 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_info	*info;
	char			*line;

	if (argc == 1)
		return (0);
	info = init_stack_info();
	info->args_list = args_list(info, argv, argc);
	ft_create_a_stack(info);
	if (ft_check_sort(info->head_a))
		write(1, "OK\n", 3);
	while (get_next_line(0, &line) == 1)
	{
		run(info, line, 1);
		free (line);
		line = NULL;
	}
	if (ft_check_sort(info->head_a) && ft_lstsize((t_list *)info->head_b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	if (line)
		free(line);
	before_living(info);
	return (0);
}
