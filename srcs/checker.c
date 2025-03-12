/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 14:39:10 by aouichou          #+#    #+#             */
/*   Updated: 2022/10/19 18:53:20 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	sort(t_main *ptr)
{
	t_moves	*tmp;

	tmp = ptr->checker_mvs;
	while (tmp)
	{
		if (!(ft_strncmp(tmp->move, "s", 1)))
			ft_swap(tmp->move);
		else if (!(ft_strncmp(tmp->move, "p", 1)))
			ft_push(tmp->move);
		else if (!(ft_strncmp(tmp->move, "r", 1)))
		{
			if (ft_strlen(tmp->move) == 2)
				ft_rotate(tmp->move);
			else if (ft_strlen(tmp->move) == 3)
				ft_r_rotate(tmp->move);
		}
		tmp = tmp->next;
	}
}

void	check_valid_ltr(char *move, char *instructions)
{
	int	i;
	int	error;

	error = 0;
	if (move[0] != 's' && move[0] != 'p' && move[0] != 'r')
		error = 1;
	i = -1;
	while (!error && move[++i])
	{
		if (move[i] != 'a' && move[i] != 'b' && move[i] != 's'
			&& move[i] != 'p' && move[i] != 'r' && move[i] != '\n')
			error = 1;
	}
	if (error)
	{
		free(move);
		free(instructions);
		ft_error("Invalid command", TRUE);
	}
}

void	check_cmds(char *move, char *instructions)
{
	int			i;
	int			mv;
	int			check;
	static int	cmds[11] = {'s' + 'a', 's' + 'b', 's' + 's', 'p' + 'a',
		'p' + 'b', 'r' + 'a', 'r' + 'b', 'r' + 'r', 'r' + 'r' + 'a',
		'r' + 'r' + 'b', 'r' + 'r' + 'r'};

	i = -1;
	mv = 0;
	check = 0;
	while (move[++i])
		mv += move[i];
	i = -1;
	while (++i < 11)
		if (mv == cmds[i] + '\n')
			check = 1;
	if (check == 0)
	{
		free(move);
		free(instructions);
		ft_error("Invalid command", TRUE);
	}
}

void	ft_parse_instructions(t_main	*ptr)
{
	int		i;
	char	*temp;
	char	*instructions;
	char	**instructions_array;
	t_moves	*move;

	instructions = ft_strnew(0);
	temp = NULL;
	temp = get_next_line(STDIN_FILENO);
	while (temp != NULL)
	{
		check_valid_ltr(temp, instructions);
		check_cmds(temp, instructions);
		instructions = ft_strjoin_free(instructions, temp, 2);
		temp = get_next_line(STDIN_FILENO);
	}
	instructions_array = ft_split(instructions, '\n');
	free(instructions);
	i = -1;
	while (instructions_array[++i])
	{
		move = creat_move(instructions_array[i]);
		ft_mvs_listadd_back(&(ptr->checker_mvs), move);
	}
	ft_free_tab(instructions_array);
}

int	main(int ac, char **av)
{
	t_main		*ptr;

	check_args(ac, av);
	ptr = ft_get_ptr();
	if (!ptr)
		return (0);
	parsing(ac, av, ptr);
	check_for_dups(ptr);
	ptr->nb_a = ft_args_listsize(ptr->head_a);
	ft_parse_instructions(ptr);
	sort(ptr);
	if (list_is_sorted(ptr->head_a) && ptr->head_b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_free_ptr();
	return (0);
}
