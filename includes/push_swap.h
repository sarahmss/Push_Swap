/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 18:56:26 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/22 19:21:05 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "../libraries/libft/libft.h"
# include "./structs.h"

void			ft_check_error(int err, char *msg, t_stack_info	*info_s);

// doubly linked list
t_node			*ft_get_new_node(int data);
t_node			*ft_insert_at_head(int data, t_node *head);
void			ft_insert_at_foot(int data, t_node *head);
t_node			*search_element(int data, t_node *head);
void			ft_free_list(t_node *head);

// stacks
void			ft_create_a_stack(t_stack_info *info_s);
int				ft_check_sort(t_node *stack);
char			**args_list(t_stack_info *info, char **argv, int argc);

// init
t_stack_info	*init_stack_info(void);

// sorting
void		ft_swap(t_node *A, t_node *B);
void		quick_sort(t_node *head, t_node *tail);

// swap
char		*swap_a(t_node *head_a);
char		*swap_b(t_node *head_b);
char		*swap_a_b(t_node *head_a, t_node *head_b);

// push
void		stack_del(t_node **head, t_node *del);
char		*push_a(t_node **head_a, t_node *head_b);
char		*push_b(t_node **head_b, t_node *head_a);

// rotate
char		*rotate_a(t_node **head_a);
char		*rotate_b(t_node **head_b);
char		*rotate_a_b(t_node **head_b, t_node **head_a);

// reverse rotate
char		*reverse_rotate_a(t_node **head_a);
char		*reverse_rotate_b(t_node **head_b);
char		*reverse_rotate_a_b(t_node **head_b, t_node **head_a);

#endif
