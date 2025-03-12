/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 19:11:53 by aouichou          #+#    #+#             */
/*   Updated: 2022/10/05 16:02:20 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	print_moves(t_moves *lst)
{
	int	i;

	i = 1;
	while (lst)
	{
		ft_printf("%s\n", lst->move);
		i++;
		lst = lst->next;
	}
}
