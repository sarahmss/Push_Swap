/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 10:15:46 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/23 17:41:14 by smodesto         ###   ########.fr       */
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
	info_s->tail_a = NULL;
	info_s->head_b = NULL;
	info_s->tail_b = NULL;
	info_s->args = 0;
	info_s->stack_len = 0;
	info_s->args_list = NULL;
	return (info_s);
}

t_worm	*init_worm(int head, int body, int tail, t_worm *w)
{
	if (w == NULL)
		w = (t_worm *)malloc(sizeof(t_worm *));
	if (!w)
		return (NULL);
	w->head = head;
	w->body = body;
	w->tail = tail;
	return (w);
}

void	ft_check_error(int err, char *msg, t_stack_info	*info_s)
{
	if (info_s != NULL)
	{
		ft_free_list(info_s->head_a);
		ft_free_list(info_s->head_b);
		free_matrix(info_s->args_list);
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

static void	run_sup(t_stack_info *info, char *operation)
{
	if (ft_strncmp(operation, "pa", 2) == 0)
		push_a(info);
	else if (ft_strncmp(operation, "pb", 2) == 0)
		push_b(info);
	else if (ft_strncmp(operation, "sa", 2) == 0)
		swap_a(info->head_a);
	else if (ft_strncmp(operation, "sb", 2) == 0)
		swap_b(info->head_b);
	else if (ft_strncmp(operation, "ss", 2) == 0)
		swap_a_b(info->head_a, info->head_b);
	else if (ft_strncmp(operation, "ra", 2) == 0)
		rotate_a(&info->head_a);
	else if (ft_strncmp(operation, "rb", 2) == 0)
		rotate_b(&info->head_b);
	else if (ft_strncmp(operation, "rr", 2) == 0)
		rotate_a_b(&info->head_a, &info->head_b);
	else if (ft_strncmp(operation, "rra", 3) == 0)
		reverse_rotate_a(&info->head_a);
	else if (ft_strncmp(operation, "rrb", 3) == 0)
		reverse_rotate_b(&info->head_b);
	else if (ft_strncmp(operation, "rrr", 3) == 0)
		reverse_rotate_a_b(&info->head_a, &info->head_b);
}

void	run(t_stack_info *info, char *operation, int times)
{
	int	i;

	i = 0;
	while (i < times)
	{
		run_sup(info, operation);
		i++;
	}
}
