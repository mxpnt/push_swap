/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:06:01 by mapontil          #+#    #+#             */
/*   Updated: 2022/01/10 15:21:50 by mapontil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "get_next_line.h"

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

// init.c
int			ft_is_sorted(t_lst **list);
void		ft_new_node(t_lst **list, int value, int pos);
void		ft_init_index(t_lst **list);
void		ft_init_lst(t_lst **lista, char **argv, t_info *info);

// do_op.c
void		ft_do_op(t_lst **lista, t_lst **listb, char *str);
void		ft_do_op2(t_lst **lista, t_lst **listb, char *str);
void		ft_read_op(t_lst **lista, t_lst **listb);

//list_op.c
void		ft_swap(t_lst **list);
void		ft_push(t_lst **src, t_lst **dst);
void		ft_rotate(t_lst **list);
void		ft_rrotate(t_lst **list);

// utils.c
int			ft_strncmp(const char *s1, const char *s2, size_t n);
long int	ft_atoi(const char *str);
void		ft_free_lst(t_lst **list);

#endif