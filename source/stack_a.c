/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:56:28 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/19 19:39:25 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_create_a_sup(int i, t_stack_info *info)
{
	int		num;

	num = 0;
	num = ft_atoi(info->args_list[i]);
	if (i == 0)
		info->head_a = ft_insert_at_head(num, info->head_a);
	else if (search_element(num, info->head_a))
		ft_check_error(1, "repeated numbers", info);
	if (i != 0)
		ft_insert_at_foot(num, info->head_a);
}

void	ft_create_a_stack(t_stack_info *info)
{
	int		i;

	i = 0;
	while (i < info->stack_len)
	{
		if (ft_strisalnum(info->args_list[i]))
			ft_create_a_sup(i, info);
		else
			ft_check_error(1, "not only int", info);
		i++;
	}
}

int	ft_check_sort(t_node *stack)
{
	if (stack != NULL)
	{
		while (stack->next != NULL)
		{
			if (stack->data > stack->next->data)
				return (0);
			stack = stack->next;
		}
	}
	return (1);
}

char	**args_list(t_stack_info *info, char **argv, int argc)
{
	char	**args_list;
	int		i;

	i = 1;
	if ((argc == 2) && argv[1] != NULL)
	{
		args_list = ft_split(argv[1], ' ');
		info->stack_len = ft_arraylen((void **)args_list);
		info->args = 1;
	}
	else
	{
		args_list = (char **)malloc(sizeof(char *) * argc);
		if (!args_list)
			ft_check_error(-1, "CREATING LIST", info);
		while (argv[i] != NULL)
		{
			args_list[i - 1] = ft_strdup(argv[i]);
			i++;
		}
		args_list[i - 1] = NULL;
		info->stack_len = argc - 1;
	}
	return (args_list);
}
