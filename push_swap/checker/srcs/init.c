/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:34:28 by mapontil          #+#    #+#             */
/*   Updated: 2022/01/10 15:39:24 by mapontil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	ft_is_sorted(t_lst **list)
{
	t_lst	*curr;

	if (*list)
	{
		curr = (*list);
		while (curr->next)
		{
			if (curr->index > curr->next->index)
				return (0);
			curr = curr->next;
		}
	}
	else
		return (0);
	return (1);
}

void	ft_new_node(t_lst **list, int value, int pos)
{
	t_lst	*curr;
	t_lst	*new_node;

	new_node = malloc(sizeof(t_lst));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->pos = pos;
	new_node->index = 0;
	new_node->next = NULL;
	curr = *list;
	while (curr->next)
		curr = curr->next;
	curr->next = new_node;
}

void	ft_init_index(t_lst **list)
{
	t_lst	*curr;
	t_lst	*next;

	if (!(*list))
		return ;
	curr = *list;
	next = curr->next;
	while (curr)
	{
		while (next)
		{
			if (curr->value > next->value)
				curr->index++;
			next = next->next;
		}
		curr = curr->next;
		next = *list;
	}
}

void	ft_init_lst(t_lst **lista, char **argv, t_info *info)
{
	int		i;

	*lista = malloc(sizeof(t_lst));
	if (!(*lista))
		return ;
	i = 1;
	(*lista)->value = ft_atoi(argv[i]);
	(*lista)->pos = 0;
	(*lista)->index = 0;
	(*lista)->next = NULL;
	info->size = 1;
	while (argv[++i])
	{
		ft_new_node(lista, ft_atoi(argv[i]), i - 1);
		info->size++;
	}
	ft_init_index(lista);
}
