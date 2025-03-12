/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:57:54 by aouichou          #+#    #+#             */
/*   Updated: 2022/10/05 16:01:02 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	calculate_cost(t_main *ptr)
{
	t_args_list	*tmp;

	tmp = ptr->head_b;
	while (tmp)
	{
		tmp->b_cost = tmp->pos;
		if (tmp->pos > ptr->nb_b / 2)
			tmp->b_cost = (ptr->nb_b - tmp->pos) * -1;
		tmp->a_cost = tmp->target_pos;
		if (tmp->target_pos > ptr->nb_a / 2)
			tmp->a_cost = (ptr->nb_a - tmp->target_pos) * -1;
		tmp = tmp->next;
	}
}
