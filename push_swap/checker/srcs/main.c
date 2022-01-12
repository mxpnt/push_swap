/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:59:19 by mapontil          #+#    #+#             */
/*   Updated: 2022/01/10 15:21:34 by mapontil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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
			ft_read_op(&lista, &listb);
			if (ft_is_sorted(&lista) && !listb)
				write(1, "OK\n", 3);
			else
				write(1, "KO\n", 3);
		}
	}
	ft_free_lst(&lista);
	ft_free_lst(&listb);
	return (0);
}
