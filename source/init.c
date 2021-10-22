/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 10:15:46 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/21 18:58:45 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack_info	*init_stack_info(void)
{
	t_stack_info	*info_s;

	info_s = (t_stack_info *)malloc(sizeof(t_stack_info));
	if (!info_s)
		ft_check_error(-2, "Initing structure", NULL);
	info_s->head_a = NULL;
	info_s->tail_a = (t_node *)malloc(sizeof(t_node *));
	info_s->tail_a = NULL;
	info_s->args = 0;
	info_s->stack_len = 0;
	info_s->args_list = NULL;
	return (info_s);
}

void	ft_check_error(int err, char *msg, t_stack_info	*info_s)
{
	if (info_s != NULL)
	{
		ft_free_list(info_s->head_a);
		free_matrix(info_s->args_list);
		free(info_s->tail_a);
		free (info_s);
	}
	if (err == -1)
	{
		write(2, "Error\n", 7);
		exit (1);
	}
	if (err == 0)
		exit (1);
	else
	{
		ft_printf("-ERRO: %s", msg);
		exit (1);
	}
}
