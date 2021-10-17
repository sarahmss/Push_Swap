/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:58:28 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/17 12:56:09 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_check_error(int err, char *msg)
{
	if (err == -1)
	{
		write(2, "Error\n", 7);
		exit (1);
	}
	if (err == -2)
	{
		ft_printf("-ERRO: %s", msg);
		exit (1);
	}
}

int	main(int argc, char **argv)
{
	if (argc <= 1)
	{
		ft_printf("Insert a list to be sorted: ./push_swap <int list> \n");
		exit (0);
	}
	ft_create_a_stack(argc, argv);
	return (0);
}
