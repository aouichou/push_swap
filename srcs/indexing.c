/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:53:34 by aouichou          #+#    #+#             */
/*   Updated: 2022/10/05 16:01:26 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	indexing(t_args_list *lst, int size)
{
	t_args_list	*tmp;
	t_args_list	*max;
	int			value;

	while (--size > 0)
	{
		tmp = lst;
		value = INT_MIN;
		max = NULL;
		while (tmp)
		{
			if (tmp->value == INT_MIN && tmp->index == 0)
				tmp->index = 1;
			if (tmp->value > value && tmp->index == 0)
			{
				value = tmp->value;
				max = tmp;
				tmp = lst;
			}
			else
				tmp = tmp->next;
		}
		if (max != NULL)
			max->index = size;
	}
}
