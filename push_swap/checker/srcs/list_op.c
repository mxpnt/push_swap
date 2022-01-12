/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 09:15:05 by mapontil          #+#    #+#             */
/*   Updated: 2022/01/10 14:30:49 by mapontil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_swap(t_lst **list)
{
	t_lst	*curr;
	t_lst	*temp;

	if (*list && (*list)->next)
	{
		curr = *list;
		temp = (*list)->next->next;
		*list = (*list)->next;
		(*list)->next = curr;
		(*list)->next->next = temp;
	}
}

void	ft_push(t_lst **src, t_lst **dst)
{
	t_lst	*curr;
	t_lst	*temp;

	if (*src)
	{
		curr = *src;
		*src = (*src)->next;
		temp = *src;
		curr->next = *dst;
		*dst = curr;
	}
}

void	ft_rotate(t_lst **list)
{
	t_lst	*curr;
	t_lst	*temp;
	t_lst	*next;

	if (*list && (*list)->next)
	{
		curr = *list;
		temp = (*list)->next;
		next = *list;
		while (curr->next)
			curr = curr->next;
		curr->next = next;
		curr->next->next = NULL;
		*list = temp;
	}
}

void	ft_rrotate(t_lst **list)
{
	t_lst	*curr;
	t_lst	*prev;

	if (*list && (*list)->next)
	{
		curr = *list;
		while (curr->next)
		{
			prev = curr;
			curr = curr->next;
		}
		curr->next = *list;
		prev->next = NULL;
		*list = curr;
	}
}
