/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 14:43:34 by aouichou          #+#    #+#             */
/*   Updated: 2022/10/18 18:48:47 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	check_for_dups(t_main *ptr)
{
	t_args_list	*head;
	t_args_list	*temp;

	head = ptr->head_a;
	while (head)
	{
		temp = head->next;
		while (temp)
		{
			if (head->value == temp->value)
				ft_error("Duplicate arguments", TRUE);
			temp = temp->next;
		}
		head = head->next;
	}
}

void	creat_list(char **tab, char *nb, t_main *ptr)
{
	long		z;
	t_args_list	*temp;

	z = ft_atoi_base(nb, "0123456789");
	if (z > INT_MAX || z < INT_MIN)
	{
		ft_free_tab(tab);
		ft_error("Argument not an INT", TRUE);
	}
	temp = ft_args_listnew(z);
	if (!temp)
	{
		ft_free_tab(tab);
		ft_error("Malloc", TRUE);
	}
	ft_args_listadd_back(&(ptr->head_a), temp);
}

void	parsing(int ac, char **av, t_main *ptr)
{
	int			i;
	int			j;
	char		**tab;

	i = 0;
	while (++i < ac)
	{
		j = -1;
		tab = ft_split(av[i], ' ');
		if (!tab)
			ft_error("Malloc", TRUE);
		while (tab[++j])
			creat_list(tab, tab[j], ptr);
		ft_free_tab(tab);
	}
}

void	check_args(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ac == 1)
		exit(0);
	while (++i < ac)
	{
		j = 0;
		if (!ft_strlen(av[i]))
			ft_error("Empty argument", TRUE);
		while (av[i][j])
		{
			if (av[i][j] == '+' || av[i][j] == '-')
			{
				if (!ft_isdigit(av[i][j + 1])
					|| (j != 0 && av[i][j - 1] != ' '))
					ft_error("Invalid arguments", TRUE);
				j++;
			}
			if (!ft_isdigit(av[i][j]) && av[i][j] != ' ')
				ft_error("Invalid arguments", TRUE);
			j++;
		}
	}
}
