/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_lft.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:00:56 by smodesto          #+#    #+#             */
/*   Updated: 2021/10/29 23:08:45 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_LFT_H
# define STRUCTS_LFT_H
# include "libft.h"

//printf
typedef struct s_format
{
	va_list	args;
	char	*temp;
	int		printed;
}			t_format;

typedef struct s_positions
{
	size_t	i;
	size_t	j;
	size_t	k;
	int		sign;
	char	*stemp;
}	t_positions;

typedef struct s_conversion
{
	int						i;
	long int				numb;
	char					*hex;
	char					*str;
}	t_conversion;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_nodel
{
	int				data;
	int				index;
	struct s_nodel	*next;
	struct s_nodel	*prev;
}	t_nodel;

#endif
