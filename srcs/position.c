/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 19:14:46 by aouichou          #+#    #+#             */
/*   Updated: 2022/10/07 18:07:32 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	lowest_index_pos(t_main *ptr, char c)
{
	t_args_list	*tmp;
	int			lowest_index;
	int			lowest_pos;

	if (c == 'a')
		tmp = ptr->head_a;
	else if (c == 'b')
		tmp = ptr->head_b;
	position(c);
	lowest_index = INT_MAX;
	if (tmp)
		lowest_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}

void	position(char c)
{
	t_main		*ptr;
	t_args_list	*tmp;
	int			i;

	ptr = ft_get_ptr();
	tmp = NULL;
	if (c == 'a')
		tmp = ptr->head_a;
	else if (c == 'b')
		tmp = ptr->head_b;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}
