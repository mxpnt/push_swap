/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 09:15:05 by mapontil          #+#    #+#             */
/*   Updated: 2022/01/05 17:25:11 by mapontil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(t_lst **list, char name)
{
	t_lst	*curr;
	t_lst	*temp;

	curr = *list;
	temp = (*list)->next->next;
	*list = (*list)->next;
	(*list)->next = curr;
	(*list)->next->next = temp;
	if (name == 'a')
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

void	ft_push(t_lst **src, t_lst **dst, char name)
{
	t_lst	*curr;
	t_lst	*temp;

	curr = *src;
	*src = (*src)->next;
	temp = *src;
	curr->next = *dst;
	*dst = curr;
	if (name == 'a')
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}

void	ft_rotate(t_lst **list, char name)
{
	t_lst	*curr;
	t_lst	*temp;
	t_lst	*next;

	curr = *list;
	temp = (*list)->next;
	next = *list;
	while (curr->next)
		curr = curr->next;
	curr->next = next;
	curr->next->next = NULL;
	*list = temp;
	if (name == 'a')
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	ft_rrotate(t_lst **list, char name)
{
	t_lst	*curr;
	t_lst	*prev;

	curr = *list;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	curr->next = *list;
	prev->next = NULL;
	*list = curr;
	if (name == 'a')
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}
