/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_lists_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 01:08:27 by aouichou          #+#    #+#             */
/*   Updated: 2022/10/05 16:00:40 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

static void	set_ptrs(t_args_list *lst, char c)
{
	t_main	*ptr;

	ptr = ft_get_ptr();
	if (c == 'a')
	{
		ptr->head_a = lst;
		ptr->nb_a = ft_args_listsize(ptr->head_a);
	}
	else if (c == 'b')
	{
		ptr->head_b = lst;
		ptr->nb_b = ft_args_listsize(ptr->head_b);
	}
}

void	args_list_swap(t_args_list *lst, char c)
{
	t_args_list	*first;
	t_args_list	*second;

	if (ft_args_listsize(lst) > 1)
	{
		first = lst->next;
		second = lst;
		if (ft_args_listsize(lst) > 2)
		{
			second->next = lst->next->next;
			second->next->prev = second;
		}
		else
			second->next = NULL;
		first->prev = NULL;
		second->prev = first;
		first->next = second;
		set_ptrs(first, c);
	}
}

void	args_list_push(t_main *ptr, t_args_list *temp, char c)
{
	if (c == 'b' && ptr->head_a)
	{
		temp = ptr->head_a;
		ptr->head_a = ptr->head_a->next;
		if (ptr->head_a)
			ptr->head_a->prev = NULL;
		temp->next = ptr->head_b;
		if (ptr->head_b)
			ptr->head_b->prev = temp;
		ptr->head_b = temp;
	}
	if (c == 'a' && ptr->head_b)
	{
		temp = ptr->head_b;
		ptr->head_b = ptr->head_b->next;
		if (ptr->head_b)
			ptr->head_b->prev = NULL;
		temp->next = ptr->head_a;
		if (ptr->head_a)
			ptr->head_a->prev = temp;
		ptr->head_a = temp;
	}
	ptr->nb_a = ft_args_listsize(ptr->head_a);
	ptr->nb_b = ft_args_listsize(ptr->head_b);
}

void	args_list_rrotate(t_args_list *to_rotate, char c)
{
	t_main		*ptr;
	t_args_list	*first;
	t_args_list	*last;

	if (to_rotate && ft_args_listsize(to_rotate) > 1)
	{
		ptr = ft_get_ptr();
		first = to_rotate;
		last = ft_args_listlast(to_rotate);
		last->prev->next = NULL;
		last->next = first;
		last->prev = NULL;
		first->prev = last;
		if (c == 'a')
			ptr->head_a = last;
		if (c == 'b')
			ptr->head_b = last;
	}
}

void	args_list_rotate(t_args_list *to_rotate, char c)
{
	t_main		*ptr;
	t_args_list	*first;
	t_args_list	*last;

	if (to_rotate && ft_args_listsize(to_rotate) > 1)
	{
		ptr = ft_get_ptr();
		first = to_rotate;
		if (c == 'a')
		{
			ptr->head_a = to_rotate->next;
			if (ptr->head_a)
				ptr->head_a->prev = NULL;
		}
		if (c == 'b')
		{
			ptr->head_b = to_rotate->next;
			if (ptr->head_b)
				ptr->head_b->prev = NULL;
		}
		last = ft_args_listlast(to_rotate);
		last->next = first;
		first->prev = last;
		first->next = NULL;
	}
}
