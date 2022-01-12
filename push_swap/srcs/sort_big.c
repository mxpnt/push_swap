/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:04:32 by mapontil          #+#    #+#             */
/*   Updated: 2022/01/10 11:28:23 by mapontil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_define_chunk(t_info *info, int size, int chunk)
{
	int	i;

	i = -1;
	while (++i < chunk)
	{
		if (size / (info->size / chunk) >= i
			&& size / (info->size / chunk) < i + 1)
		{
			info->max = info->size - (i * (info->size / chunk));
			info->min = info->max - (info->size / chunk);
		}
	}
}

void	ft_push_hold(t_lst **lista, t_lst **listb, int move, int mod)
{
	while (move > 0)
	{
		if (mod == 1)
			ft_rotate(lista, 'a');
		else if (mod == 2)
			ft_rrotate(lista, 'a');
		else if (mod == 3)
			ft_rotate(listb, 'b');
		else
			ft_rrotate(listb, 'b');
		move--;
	}
	if (mod == 1 || mod == 2)
		ft_push(lista, listb, 'b');
	else
		ft_push(listb, lista, 'a');
}

void	ft_which_hold(t_lst **lista, t_lst **listb, t_info *info, int mod)
{
	if (mod == 1)
	{
		if (info->hold2 > info->i / 2)
		{
			info->hold2 = (info->hold2 - info->i) * -1;
			if (info->hold2 < info->hold1 - 1)
				ft_push_hold(lista, listb, info->hold2, 2);
			else
				ft_push_hold(lista, listb, info->hold1 - 1, 1);
		}
		else
			ft_push_hold(lista, listb, info->hold1 - 1, 1);
	}
	else
	{
		if (info->hold1 > info->i / 2)
		{
			info->hold1 = (info->hold1 - info->i) * -1;
			ft_push_hold(lista, listb, info->hold1, 4);
		}
		else
			ft_push_hold(lista, listb, info->hold1, 3);
	}
}

void	ft_sort_big(t_lst **lista, t_lst **listb, t_info *info, int chunk)
{
	t_lst	*curr;

	ft_define_chunk(info, info->size - 1, chunk);
	while (*lista)
	{
		curr = (*lista);
		info->i = 0;
		info->hold1 = 0;
		info->hold2 = 0;
		while (curr)
		{
			if (curr->index >= info->min && curr->index <= info->max
				&& !info->hold1)
				info->hold1 = info->i + 1;
			if (curr->index >= info->min && curr->index <= info->max)
				info->hold2 = info->i;
			curr = curr->next;
			info->i++;
		}
		ft_which_hold(lista, listb, info, 1);
		ft_define_chunk(info, info->i - 2, chunk);
	}
	ft_sort_big1(lista, listb, info);
}

void	ft_sort_big1(t_lst **lista, t_lst **listb, t_info *info)
{
	t_lst	*curr;
	int		value;

	while (*listb)
	{
		curr = (*listb);
		info->i = 0;
		value = curr->index;
		info->hold1 = 0;
		while (curr)
		{
			if (curr->index >= value)
			{
				value = curr->index;
				info->hold1 = info->i;
			}
			info->i++;
			curr = curr->next;
		}
		ft_which_hold(lista, listb, info, 2);
	}
}
