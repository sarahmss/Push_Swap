/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_optimize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 19:00:05 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/01 22:03:58 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_operations	*create_node(char *data)
{
	t_operations	*new_node;

	new_node = (t_operations *)malloc(sizeof(t_operations));
	if (!new_node)
		ft_check_error(-1, "ERR_CREATE_NODE", NULL);
	new_node->op = data;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	insert_at_foot(char *data, t_operations *head)
{
	t_operations	*new_node;
	t_operations	*temp;

	new_node = create_node(data);
	temp = head;
	if (temp->next == NULL)
	{
		head->next = new_node;
		new_node->prev = head;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
		new_node->prev = temp;
	}
}

void	create_operations(t_stack_info *info, char *operation)
{
	t_operations	*new_node;

	if (info->op == 0)
	{
		new_node = create_node(operation);
		if (info->inst == NULL)
			info->inst = new_node;
	}
	else
		insert_at_foot(operation, info->inst);
}

static void	substitute(t_operations *temp, t_operations *head)
{
	char	*op;

	op = NULL;
	if ((ft_strcmp(temp->op, "sa") && ft_strcmp(temp->next->op, "sb"))
		|| (ft_strcmp(temp->op, "sb") && ft_strcmp(temp->next->op, "sa")))
		op = ft_strdup("ss");
	if ((ft_strcmp(temp->op, "ra") && ft_strcmp(temp->next->op, "rb"))
		|| (ft_strcmp(temp->op, "rb") && ft_strcmp(temp->next->op, "ra")))
		op = ft_strdup("rr");
	if ((ft_strcmp(temp->op, "rra") && ft_strcmp(temp->next->op, "rrb"))
		|| (ft_strcmp(temp->op, "rrb") && ft_strcmp(temp->next->op, "rra")))
		op = ft_strdup("rrr");
	if (op != NULL)
	{
		temp->op = op;
		stack_del((t_node **)&head, (t_node *)temp->next);
		free(op);
	}
}

void	optimize_operations(t_operations *op)
{
	t_operations	*temp;
	t_operations	*head;

	temp = op;
	head = op;
	while (temp->next != NULL)
	{
		substitute(temp, head);
		temp = temp->next;
	}
}
