/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 01:06:51 by aouichou          #+#    #+#             */
/*   Updated: 2022/10/05 16:01:57 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	ft_swap(char *str)
{
	t_main	*ptr;
	t_moves	*move;

	ptr = ft_get_ptr();
	if (!ft_strncmp(str, "sa", 2))
	{
		args_list_swap(ptr->head_a, 'a');
		move = creat_move("sa");
		ft_mvs_listadd_back(&(ptr->moves), move);
	}
	else if (!ft_strncmp(str, "sb", 2))
	{
		args_list_swap(ptr->head_b, 'b');
		move = creat_move("sb");
		ft_mvs_listadd_back(&(ptr->moves), move);
	}
	else if (!ft_strncmp(str, "ss", 2))
	{
		args_list_swap(ptr->head_a, 'a');
		args_list_swap(ptr->head_b, 'b');
		move = creat_move("ss");
		ft_mvs_listadd_back(&(ptr->moves), move);
	}
}

void	ft_push(char *str)
{
	t_main	*ptr;
	t_moves	*move;

	ptr = ft_get_ptr();
	if (!ft_strncmp(str, "pa", 2))
	{
		args_list_push(ptr, NULL, 'a');
		move = creat_move("pa");
		ft_mvs_listadd_back(&(ptr->moves), move);
	}
	else if (!ft_strncmp(str, "pb", 2))
	{
		args_list_push(ptr, NULL, 'b');
		move = creat_move("pb");
		ft_mvs_listadd_back(&(ptr->moves), move);
	}
}

void	ft_rotate(char *str)
{
	t_main	*ptr;
	t_moves	*move;

	ptr = ft_get_ptr();
	if (!ft_strncmp(str, "ra", 2))
	{
		args_list_rotate(ptr->head_a, 'a');
		move = creat_move("ra");
		ft_mvs_listadd_back(&(ptr->moves), move);
	}
	else if (!ft_strncmp(str, "rb", 2))
	{
		args_list_rotate(ptr->head_b, 'b');
		move = creat_move("rb");
		ft_mvs_listadd_back(&(ptr->moves), move);
	}
	else if (!ft_strncmp(str, "rr", 2))
	{
		args_list_rotate(ptr->head_a, 'a');
		args_list_rotate(ptr->head_b, 'b');
		move = creat_move("rr");
		ft_mvs_listadd_back(&(ptr->moves), move);
	}
}

void	ft_r_rotate(char *str)
{
	t_main	*ptr;
	t_moves	*move;

	ptr = ft_get_ptr();
	if (!ft_strncmp(str, "rra", 3))
	{
		args_list_rrotate(ptr->head_a, 'a');
		move = creat_move("rra");
		ft_mvs_listadd_back(&(ptr->moves), move);
	}
	else if (!ft_strncmp(str, "rrb", 3))
	{
		args_list_rrotate(ptr->head_b, 'b');
		move = creat_move("rrb");
		ft_mvs_listadd_back(&(ptr->moves), move);
	}
	else if (!ft_strncmp(str, "rrr", 3))
	{
		args_list_rrotate(ptr->head_a, 'a');
		args_list_rrotate(ptr->head_b, 'b');
		move = creat_move("rrr");
		ft_mvs_listadd_back(&(ptr->moves), move);
	}
}
