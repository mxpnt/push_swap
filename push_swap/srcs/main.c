/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 09:54:15 by mapontil          #+#    #+#             */
/*   Updated: 2022/01/10 13:23:53 by mapontil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_lst	*lista;
	t_lst	*listb;
	t_info	info;

	if (argc > 1)
	{
		if (ft_error(argv) == 0)
		{
			ft_init_lst(&lista, argv, &info);
			if (!ft_is_sorted(&lista))
			{
				if ((argc == 3 || argc == 4))
					ft_sort_small(&lista, argc - 1);
				else if (argc == 5 || argc == 6)
					ft_sort_medium(&lista, &listb, &info);
				else if (argc <= 101)
					ft_sort_big(&lista, &listb, &info, 5);
				else
					ft_sort_big(&lista, &listb, &info, 11);
			}	
		}
	}
	ft_free_lst(&lista);
	return (0);
}
