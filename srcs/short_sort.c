/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 01:18:15 by aouichou          #+#    #+#             */
/*   Updated: 2022/10/05 18:14:10 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	push_to_b(void)
{
	t_main	*ptr;
	int		j;
	int		i;
	int		size;

	ptr = ft_get_ptr();
	size = ptr->nb_a;
	i = 0;
	while (i++ < 2)
	{
		j = 0;
		if (list_pos(list_min(ptr->head_a), ptr->head_a) < size / 2)
			j = 1;
		while (ptr->head_a->value != list_min(ptr->head_a))
		{
			if (j)
				ft_rotate("ra");
			else
				ft_r_rotate("rra");
		}
		ft_push("pb");
	}
}

void	medium_sort(void)
{
	t_main	*ptr;
	int		size;

	ptr = ft_get_ptr();
	size = ptr->nb_a;
	if (size > 3)
		push_to_b();
	while (!list_is_sorted(ptr->head_a))
	{
		if (ptr->head_a->value >= list_max(ptr->head_a, 0))
			ft_rotate("ra");
		else if (ptr->head_a->value > ptr->head_a->next->value)
			ft_swap("sa");
		else
			ft_rotate("ra");
	}
	if (size > 3)
	{
		ft_push("pa");
		ft_push("pa");
	}
}

int	biggest_index(t_args_list *lst)
{
	int	index;

	index = lst->index;
	while (lst)
	{
		if (lst->index > index)
			index = lst->index;
		lst = lst->next;
	}
	return (index);
}

void	short_sort(void)
{
	t_main	*ptr;
	int		biggest;

	ptr = ft_get_ptr();
	if (list_is_sorted(ptr->head_a))
		return ;
	biggest = biggest_index(ptr->head_a);
	if (ptr->head_a->index == biggest)
		ft_rotate("ra");
	else if (ptr->head_a->next->index == biggest)
		ft_r_rotate("rra");
	if (ptr->head_a->index > ptr->head_a->next->index)
		ft_swap("sa");
}
