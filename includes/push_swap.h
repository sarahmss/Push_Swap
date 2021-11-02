/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 18:56:26 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/01 21:12:20 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "../libraries/libft/libft.h"
# include "./structs.h"

// ut_doubly_linked_list
t_node			*ft_get_new_node(int data);
t_node			*ft_insert_at_head(int data, t_node *head);
void			ft_insert_at_foot(int data, t_node *head);
void			ft_free_list(t_node *head);

// ut_searching
int				tail_or_head(t_stack_info *info, t_node *top, t_node *head);
t_node			*search_element(int data, t_node *head, int mod);
t_node			*search_in_range(int left, int right, t_node *node, int mod);
int				from_head(t_node *head, t_node *smallest);
int				from_tail(t_node *tail, t_node *smallest);
void			sort_b(t_stack_info *info, int min, int max, int div);

// ut_stacks
void			ft_create_a_stack(t_stack_info *info_s);
char			**args_list(t_stack_info *info, char **argv, int argc);
int				ft_check_sort(t_node *stack);

// ut_init
t_stack_info	*init_stack_info(void);
void			ft_check_error(int err, char *msg, t_stack_info	*info_s);
void			before_living(t_stack_info *info_s);
t_worm			*init_worm(t_stack_info *info, t_worm *w);

// st_sorting
void			ft_swap(t_node *A, t_node *B);
void			quick_sort(t_node *head, t_node *tail);
void			ft_put_index(t_stack_info *info);
void			sort_small_stack(t_stack_info *info);
void			sort_big_stack(t_stack_info *info);

//st_aux
t_stack_aux		*set_aux(t_stack_info *info, int *l_bound, int *r_bound);
void			sort_b(t_stack_info *info, int min, int max, int div);
void			set_chuncks(t_stack_info *info, int *l, int *r, int *div);
t_stack_aux		*change_chuncks(t_stack_info *info, int *l, int *r, int *div);

// op_run
void			run(t_stack_info *info, char *operation, int times);
void			ft_print_op(t_operations *operations);

// op_swap
void			swap_a(t_node *head_a, t_stack_info *info);
void			swap_b(t_node *head_b, t_stack_info *info);
void			swap_a_b(t_node *head_a, t_node *head_b, t_stack_info *info);

// op_push
void			stack_del(t_node **head, t_node *del);
void			push_a(t_stack_info *info);
void			push_b(t_stack_info *info);

// op_rotate
void			rotate_a(t_node **head_a, t_stack_info *info);
void			rotate_b(t_node **head_b, t_stack_info *info);
void			rotate_a_b(t_node **head_b, t_node **head_a, t_stack_info *inf);

// op_reverse_rotate
void			reverse_rotate_a(t_node **head_a, t_stack_info *info);
void			reverse_rotate_b(t_node **head_b, t_stack_info *info);
void			reverse_rotate_a_b(t_node **head_b, t_node **head_a,
					t_stack_info *inf);

// op_optimize
void			create_operations(t_stack_info *info, char *operation);
void			optimize_operations(t_operations *op);

#endif
