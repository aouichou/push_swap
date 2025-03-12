/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 05:26:38 by aouichou          #+#    #+#             */
/*   Updated: 2022/10/05 16:00:55 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	target(t_args_list *lst, int b_index, int t_index, int t_pos)
{
	t_args_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->index > b_index && tmp->index < t_index)
		{
			t_index = tmp->index;
			t_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (t_index != INT_MAX)
		return (t_pos);
	tmp = lst;
	while (tmp)
	{
		if (tmp->index < t_index)
		{
			t_index = tmp->index;
			t_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (t_pos);
}

void	target_position(t_main *ptr)
{
	t_args_list	*tmp;
	int			t_pos;

	tmp = ptr->head_b;
	position('a');
	position('b');
	t_pos = 0;
	while (tmp)
	{
		t_pos = target(ptr->head_a, tmp->index, INT_MAX, t_pos);
		tmp->target_pos = t_pos;
		tmp = tmp->next;
	}
}

void	push_all(t_main *ptr)
{
	int	size;
	int	nb_pushed;
	int	i;

	size = ptr->nb_a;
	nb_pushed = 0;
	i = 0;
	while (i < size && nb_pushed < size / 2)
	{
		if (ptr->head_a->index <= size / 2)
		{
			ft_push("pb");
			nb_pushed++;
		}
		else
			ft_rotate("ra");
		i++;
	}
	while (size != nb_pushed)
	{
		ft_push("pb");
		nb_pushed++;
	}
}

void	rotate_stack(t_main *ptr)
{
	int	size;
	int	lowest_pos;

	size = ptr->nb_a;
	lowest_pos = lowest_index_pos(ptr, 'a');
	if (lowest_pos > size / 2)
	{
		while (lowest_pos < size)
		{
			ft_r_rotate("rra");
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ft_rotate("ra");
			lowest_pos--;
		}
	}
}

void	big_sort(void)
{
	t_main	*ptr;

	ptr = ft_get_ptr();
	push_all(ptr);
	while (ptr->head_b)
	{
		target_position(ptr);
		calculate_cost(ptr);
		move(ptr);
	}
	if (!list_is_sorted(ptr->head_a))
		rotate_stack(ptr);
}
