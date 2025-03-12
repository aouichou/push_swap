/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 22:24:39 by aouichou          #+#    #+#             */
/*   Updated: 2022/10/05 18:08:50 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	main(int ac, char **av)
{
	t_main	*ptr;

	check_args(ac, av);
	ptr = ft_get_ptr();
	if (!ptr)
		return (0);
	parsing(ac, av, ptr);
	check_for_dups(ptr);
	ptr->nb_a = ft_args_listsize(ptr->head_a);
	indexing(ptr->head_a, ptr->nb_a + 1);
	if (!list_is_sorted(ptr->head_a))
	{
		if (ptr->nb_a == 2)
			ft_swap("sa");
		else if (ptr->nb_a == 3)
			short_sort();
		else if (ptr->nb_a <= 8)
			medium_sort();
		else
			big_sort();
	}
	print_moves(ptr->moves);
	ft_free_ptr();
	return (0);
}
