/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:47:16 by mapontil          #+#    #+#             */
/*   Updated: 2022/01/10 15:29:11 by mapontil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_do_op(t_lst **lista, t_lst **listb, char *str)
{
	if (ft_strncmp(str, "sa", ft_strlen(str) - 1) == 0)
		ft_swap(lista);
	else if (ft_strncmp(str, "sb", ft_strlen(str) - 1) == 0)
		ft_swap(listb);
	else if (ft_strncmp(str, "ss", ft_strlen(str) - 1) == 0)
	{
		ft_swap(lista);
		ft_swap(listb);
	}
	else if (ft_strncmp(str, "pa", ft_strlen(str) - 1) == 0)
		ft_push(listb, lista);
	else if (ft_strncmp(str, "pb", ft_strlen(str) - 1) == 0)
		ft_push(lista, listb);
	else if (ft_strncmp(str, "ra", ft_strlen(str) - 1) == 0)
		ft_rotate(lista);
	else if (ft_strncmp(str, "rb", ft_strlen(str) - 1) == 0)
		ft_rotate(listb);
	else if (ft_strncmp(str, "rr", ft_strlen(str) - 1) == 0)
	{
		ft_rotate(lista);
		ft_rrotate(listb);
	}
	else
		ft_do_op2(lista, listb, str);
}

void	ft_do_op2(t_lst **lista, t_lst **listb, char *str)
{
	if (ft_strncmp(str, "rra", ft_strlen(str) - 1) == 0)
		ft_rrotate(lista);
	else if (ft_strncmp(str, "rrb", ft_strlen(str) - 1) == 0)
		ft_rrotate(listb);
	else if (ft_strncmp(str, "rrr", ft_strlen(str) - 1) == 0)
	{
		ft_rrotate(lista);
		ft_rrotate(listb);
	}
	else
	{
		ft_free_lst(lista);
		ft_free_lst(listb);
		ft_error_msg(0);
	}
}

void	ft_read_op(t_lst **lista, t_lst **listb)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		ft_do_op(lista, listb, str);
		free(str);
		str = get_next_line(0);
	}
}
