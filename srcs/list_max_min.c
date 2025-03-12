/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_max_min.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:25:17 by aouichou          #+#    #+#             */
/*   Updated: 2022/10/05 16:01:31 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	list_max(t_args_list *list, int skip)
{
	int	max;

	max = INT_MIN;
	while (list)
	{
		if (list->value > max && list->value != skip)
			max = list->value;
		list = list->next;
	}
	return (max);
}

int	list_min(t_args_list *list)
{
	int	min;

	min = INT_MAX;
	while (list)
	{
		if (list->value < min)
			min = list->value;
		list = list->next;
	}
	return (min);
}

int	list_pos(int value, t_args_list *list)
{
	int	pos;

	pos = 0;
	while (list)
	{
		if (list->value == value)
			return (pos);
		list = list->next;
		pos++;
	}
	return (pos);
}
