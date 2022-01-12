/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 09:54:50 by mapontil          #+#    #+#             */
/*   Updated: 2022/01/10 11:32:19 by mapontil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_lst
{
	int				value;
	int				pos;
	int				index;
	struct s_lst	*next;
}				t_lst;

typedef struct s_info
{
	int	size;
	int	min;
	int	max;
	int	hold1;
	int	hold2;
	int	i;
}				t_info;

// error.c
int			ft_check_nb(char *arg);
int			ft_check_int(char *arg);
int			ft_check_dup(char *arg, char **argv, int i);
int			ft_error(char **argv);
int			ft_error_msg(int code);

// utils.c
long int	ft_atoi(const char *str);
void		ft_free_lst(t_lst **list);

//init.c
int			ft_is_sorted(t_lst **list);
void		ft_new_node(t_lst **root, int value, int pos);
void		ft_init_index(t_lst **list);
void		ft_init_lst(t_lst **lista, char **argv, t_info *info);

//sort.c
void		ft_sort_small(t_lst **list, int size);
void		ft_sort_small1(t_lst **list, int n1, int n2, int n3);
void		ft_sort_medium(t_lst **lista, t_lst **listb, t_info *info);
void		ft_sort_medium1(t_lst **lista, t_lst **listb, t_info *info);
void		ft_sort_medium2(t_lst **lista, t_lst **listb, t_info *info);

//sort_big.c
void		ft_define_chunk(t_info *info, int size, int chunk);
void		ft_push_hold(t_lst **lista, t_lst **listb, int move, int mod);
void		ft_which_hold(t_lst **lista, t_lst **listb, t_info *info, int i);
void		ft_sort_big(t_lst **lista, t_lst **listb, t_info *info, int chunk);
void		ft_sort_big1(t_lst **lista, t_lst **listb, t_info *info);

//list_op.c
void		ft_swap(t_lst **list, char name);
void		ft_push(t_lst **src, t_lst **dst, char name);
void		ft_rotate(t_lst **list, char name);
void		ft_rrotate(t_lst **list, char name);

#endif