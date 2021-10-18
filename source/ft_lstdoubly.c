/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdoubly.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 09:58:24 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/18 11:38:26 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
Creates a new element at a doubly linked list and storage data in it
*/
t_node	*ft_get_new_node(int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		ft_check_error(-2, "ERR_CREATE_NODE", NULL);
	new_node->data = data;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

/*
Insert a new element at the top of a doubly linked list
*/
t_node	*ft_insert_at_head(int data, t_node *head)
{
	t_node	*new_node;

	new_node = ft_get_new_node(data);
	if (head == NULL)
		head = new_node;
	else
	{
		head->prev = new_node;
		new_node->next = head;
		head = new_node;
	}
	return (new_node);
}

/*
Insert a new element at the bottom of a doubly linked list
*/
void	ft_insert_at_foot(int data, t_node *head)
{
	t_node	*new_node;
	t_node	*temp;

	new_node = ft_get_new_node(data);
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

/*
Returns a pointer if the element is found in the list, otherwise returns null
*/
t_node	*search_element(int data, t_node *head)
{
	t_node	*temp;

	temp = head;
	while ((temp->data != data) && (temp->next != NULL))
	{
		temp = temp->next;
		if (temp->data == data)
			return (temp);
	}
	return (NULL);
}

void	ft_free_list(t_node *head)
{
	t_node	*current;
	t_node	*next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free (current);
		current = next;
	}
}
