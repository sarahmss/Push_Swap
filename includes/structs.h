/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 08:51:24 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/29 23:24:55 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_worm
{
	int	head;
	int	body;
	int	tail;
}	t_worm;

typedef struct s_stack_info
{
	t_node	*head_a;
	t_node	*head_b;
	t_node	*temp;
	int		stack_len;
	int		args;
	char	**args_list;
	t_worm	*w;
	int		op;
	int		sair;
}	t_stack_info;

typedef struct s_stack_aux
{
	t_node			*hold_1;
	t_node			*hold_2;
	t_node			*head;
	t_node			*tail;
	int				t1;
	int				t2;
	t_stack_info	*info;
}	t_stack_aux;

#endif
