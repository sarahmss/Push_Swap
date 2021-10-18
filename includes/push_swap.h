/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 18:56:26 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/18 11:38:16 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "../libraries/libft/libft.h"
# include "./structs.h"

void	ft_check_error(int err, char *msg, t_stack_info	*info_s);

// doubly linked list
t_node	*ft_get_new_node(int data);
t_node	*ft_insert_at_head(int data, t_node *head);
void	ft_insert_at_foot(int data, t_node *head);
t_node	*search_element(int data, t_node *head);
void	ft_free_list(t_node *head);

// stacks
t_node	*ft_create_a_stack(int len_s, char **str_stack, t_stack_info *info_s);
int		ft_check_sort(t_node *stack);

// init
t_stack_info	*init_stack_info(int len_stack_a);


#endif