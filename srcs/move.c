/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 04:14:06 by aouichou          #+#    #+#             */
/*   Updated: 2022/10/05 16:05:34 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

static void	rotate_both(int *a_cost, int *b_cost)
{
	while (*a_cost > 0 && *b_cost > 0)
	{
		(*a_cost)--;
		(*b_cost)--;
		ft_rotate("rr");
	}
}

static void	r_rotate_both(int *a_cost, int *b_cost)
{
	while (*a_cost < 0 && *b_cost < 0)
	{
		(*a_cost)++;
		(*b_cost)++;
		ft_r_rotate("rrr");
	}
}

static void	rotate(int *cost, char c)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			if (c == 'a')
				ft_rotate("ra");
			else if (c == 'b')
				ft_rotate("rb");
			(*cost)--;
		}
		else if (*cost < 0)
		{
			if (c == 'a')
				ft_r_rotate("rra");
			else if (c == 'b')
				ft_r_rotate("rrb");
			(*cost)++;
		}
	}
}

void	rotate_and_push(int a_cost, int b_cost)
{
	if (a_cost < 0 && b_cost < 0)
		r_rotate_both(&a_cost, &b_cost);
	else if (a_cost > 0 && b_cost > 0)
		rotate_both(&a_cost, &b_cost);
	rotate(&a_cost, 'a');
	rotate(&b_cost, 'b');
	ft_push("pa");
}

void	move(t_main *ptr)
{
	t_args_list	*tmp;
	int			a_cost;
	int			b_cost;
	int			cheapest;

	tmp = ptr->head_b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (ft_abs(tmp->a_cost) + ft_abs(tmp->b_cost) < ft_abs(cheapest))
		{
			cheapest = ft_abs(tmp->a_cost) + ft_abs(tmp->b_cost);
			a_cost = tmp->a_cost;
			b_cost = tmp->b_cost;
		}
		tmp = tmp->next;
	}
	rotate_and_push(a_cost, b_cost);
}
