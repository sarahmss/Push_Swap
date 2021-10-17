/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 08:51:24 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/17 12:48:46 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# define WIN_WIDTH		1080
# define WIN_HEIGHT		600
# define MENU_WIDTH		200

# define WIN_CENTER_X	400
# define WIN_CENTER_Y	300

//Colors
# define RED				0XFF2222
# define GREEN				0X22FF22
# define BLUE				0X2222FF
# define PURPLE				0XFF22FF
# define WHITE				0XFFFFFF
# define GREY				0XAAAAAA
# define DGREY				0X444444
# define BACKGROUND			0X222222
# define MENU_BACKGROUND	1973790
# define TEXT_COLOR			0XEAEAEA

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

#endif
