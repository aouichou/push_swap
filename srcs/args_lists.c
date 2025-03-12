/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 23:53:11 by aouichou          #+#    #+#             */
/*   Updated: 2022/10/05 16:00:46 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

t_args_list	*ft_args_listnew(int value)
{
	t_args_list	*new;

	new = (t_args_list *)malloc(sizeof(t_args_list));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->pos = 0;
	new->a_cost = 0;
	new->b_cost = 0;
	new->target_pos = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_args_list	*ft_args_listlast(t_args_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
			lst = lst->next;
	return (lst);
}

void	ft_args_listadd_back(t_args_list **lst, t_args_list *nw)
{
	t_args_list	*last;

	if (!*lst)
	{
		*lst = nw;
		return ;
	}
	last = ft_args_listlast(*lst);
	last->next = nw;
	nw->prev = last;
}

int	ft_args_listsize(t_args_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

int	ft_args_list_pos(t_args_list *lst, int value)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (lst->value == value)
			break ;
		i++;
		lst = lst->next;
	}
	return (i);
}
