/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 00:56:05 by aouichou          #+#    #+#             */
/*   Updated: 2022/10/05 16:01:50 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

t_moves	*ft_mvs_listnew(char *move)
{
	t_moves	*new;

	new = (t_moves *)malloc(sizeof(t_moves));
	if (!new)
		return (NULL);
	new->move = ft_strdup(move);
	new->next = NULL;
	return (new);
}

t_moves	*ft_mvs_listlast(t_moves *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
			lst = lst->next;
	return (lst);
}

void	ft_mvs_listadd_back(t_moves **lst, t_moves *nw)
{
	t_moves	*last;

	if (!*lst)
	{
		*lst = nw;
		return ;
	}
	last = ft_mvs_listlast(*lst);
	last->next = nw;
}

int	ft_mvs_listsize(t_moves *lst)
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

t_moves	*creat_move(char *str)
{
	t_moves	*move;

	move = ft_mvs_listnew(str);
	if (!move)
		ft_error("Malloc", TRUE);
	return (move);
}
