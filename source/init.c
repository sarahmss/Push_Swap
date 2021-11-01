/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 10:15:46 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/01 13:50:20 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack_info	*init_stack_info(void)
{
	t_stack_info	*info_s;

	info_s = (t_stack_info *)malloc(sizeof(t_stack_info));
	if (!info_s)
		ft_check_error(-1, "Initing structure", NULL);
	info_s->head_a = NULL;
	info_s->head_b = NULL;
	info_s->temp = NULL;
	info_s->args = 0;
	info_s->stack_len = 0;
	info_s->args_list = NULL;
	info_s->w = NULL;
	info_s->op = 0;
	info_s->cont = 0;
	return (info_s);
}

t_worm	*init_worm(t_stack_info *info, t_worm *w)
{
	if (w == NULL)
		w = (t_worm *)malloc(sizeof(t_worm));
	if (!w)
		ft_check_error(-1, "init worm", info);
	w->head = info->head_a->data;
	w->body = info->head_a->next->data;
	w->tail = info->head_a->next->next->data;
	return (w);
}

void	before_living(t_stack_info *info_s)
{
	if (info_s != NULL)
	{
		free_matrix(info_s->args_list);
		ft_free_list(info_s->head_a);
		ft_free_list(info_s->head_b);
		if (info_s->w)
			free(info_s->w);
		free (info_s);
	}
}
/*
	-1: ERROR\n
	0: exit
	else:-ERRO msg
*/

void	ft_check_error(int err, char *msg, t_stack_info	*info_s)
{
	before_living(info_s);
	if (err == -1)
	{
		write(2, "Error\n", 6);
		exit (0);
	}
	if (err == 0)
		exit (0);
	else
	{
		ft_printf("-ERRO: %s", msg);
		exit (0);
	}
}
