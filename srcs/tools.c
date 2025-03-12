/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 22:26:53 by aouichou          #+#    #+#             */
/*   Updated: 2022/10/24 17:53:17 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	return (nbr);
}

int	list_is_sorted(t_args_list *head)
{
	if (!head)
		return (-1);
	while (head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

int	ft_count_tab(char **tab)
{
	int		count;

	count = 0;
	while (tab[count])
		count++;
	return (count);
}

t_main	*ft_get_ptr(void)
{
	static t_main	*ptr = NULL;

	if (!ptr)
	{
		ptr = (t_main *)malloc(sizeof(t_main));
		if (!(ptr))
			return (NULL);
		ptr->head_a = NULL;
		ptr->nb_a = 0;
		ptr->head_b = NULL;
		ptr->nb_b = 0;
		ptr->moves = NULL;
		ptr->checker_mvs = NULL;
	}
	return (ptr);
}

void	ft_error(char *error, int mod_exit)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(error, 2);
	ft_putstr_fd(BLANK, 2);
	if (mod_exit)
	{
		ft_free_ptr();
		exit(-1);
	}
}
