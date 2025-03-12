/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 03:24:49 by aouichou          #+#    #+#             */
/*   Updated: 2022/10/05 16:01:20 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	ft_free_ptr(void)
{
	t_main		*ptr;

	ptr = ft_get_ptr();
	ft_free_args(ptr->head_a);
	ft_free_args(ptr->head_b);
	ft_free_moves(ptr->moves);
	ft_free_moves(ptr->checker_mvs);
	free(ptr);
}

void	ft_free_args(t_args_list *head)
{
	t_args_list	*temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

void	ft_free_moves(t_moves *head)
{
	t_moves	*temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp->move);
		free(temp);
	}
}
