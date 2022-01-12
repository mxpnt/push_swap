/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 10:57:04 by mapontil          #+#    #+#             */
/*   Updated: 2022/01/10 11:32:14 by mapontil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_small(t_lst **list, int size)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = (*list)->index;
	n2 = (*list)->next->index;
	if (size == 3)
		n3 = (*list)->next->next->index;
	if (size == 2 && n1 < n2)
		return ;
	if ((n2 < n1 && n1 < n3) || (size == 2 && n2 < n1))
		ft_swap(list, 'a');
	else if (n3 < n1 && n1 < n2)
		ft_rrotate(list, 'a');
	else
		ft_sort_small1(list, n1, n2, n3);
}

void	ft_sort_small1(t_lst **list, int n1, int n2, int n3)
{
	if (n3 < n2 && n2 < n1)
	{
		ft_swap(list, 'a');
		ft_rrotate(list, 'a');
	}
	else if (n1 < n3 && n3 < n2)
	{
		ft_swap(list, 'a');
		ft_rotate(list, 'a');
	}
	else if (n2 < n3 && n3 < n1)
		ft_rotate(list, 'a');
}

void	ft_sort_medium(t_lst **lista, t_lst **listb, t_info *info)
{
	ft_push(lista, listb, 'b');
	if (info->size == 5)
		ft_push(lista, listb, 'b');
	ft_sort_small(lista, 3);
	if (info->size == 5)
	{
		if ((*listb)->index < (*listb)->next->index)
			ft_rotate(listb, 'b');
		if ((*lista)->index == (*listb)->index + 1)
		{
			ft_push(listb, lista, 'a');
			ft_push(listb, lista, 'a');
			return ;
		}
		ft_sort_medium1(lista, listb, info);
	}
	else
		ft_sort_medium2(lista, listb, info);
}

void	ft_sort_medium1(t_lst **lista, t_lst **listb, t_info *info)
{
	if ((*lista)->index == 0 && (*listb)->index == 4 \
		&& (*listb)->next->index == 3)
	{
		ft_push(listb, lista, 'a');
		ft_push(listb, lista, 'a');
		ft_rotate(lista, 'a');
		ft_rotate(lista, 'a');
		return ;
	}
	if ((*listb)->index == (*listb)->next->index + 1)
	{
		ft_rrotate(lista, 'a');
		ft_push(listb, lista, 'a');
		ft_push(listb, lista, 'a');
		while ((*lista)->index != 0)
			ft_rrotate(lista, 'a');
		return ;
	}
	while ((*lista)->next->next->index != (*listb)->index - 1)
		ft_rrotate(lista, 'a');
	ft_push(listb, lista, 'a');
	ft_sort_medium2(lista, listb, info);
}

void	ft_sort_medium2(t_lst **lista, t_lst **listb, t_info *info)
{
	if ((*listb)->index != 0)
	{
		if (info->size == 5)
			while ((*lista)->next->next->next->index != (*listb)->index - 1)
				ft_rrotate(lista, 'a');
		else
			while ((*lista)->next->next->index != (*listb)->index - 1)
				ft_rrotate(lista, 'a');
	}	
	else
		while ((*lista)->index != 1)
			ft_rotate(lista, 'a');
	ft_push(listb, lista, 'a');
	while ((*lista)->index != 0)
		ft_rrotate(lista, 'a');
}
