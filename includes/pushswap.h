/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 22:21:41 by aouichou          #+#    #+#             */
/*   Updated: 2022/10/02 17:14:31 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft.h"
# include <limits.h>

# define RED	       		"\033[1;31m"
# define GREEN	       		"\033[1;32m"
# define CYAN	       		"\033[1;36m"
# define BLUE	       		"\033[1;34m"
# define YELLOW	       		"\033[1;33m"
# define BLANK	       		"\033[0m"

enum	e_bool
{
	FALSE,
	TRUE
};

typedef struct s_moves
{
	char				*move;
	struct s_moves		*next;
}						t_moves;

typedef struct s_args_list
{
	int					value;
	int					index;
	int					pos;
	int					a_cost;
	int					b_cost;
	int					target_pos;
	struct s_args_list	*next;
	struct s_args_list	*prev;
}						t_args_list;

typedef struct s_main
{
	int					target;
	int					nb_a;
	int					nb_b;
	t_args_list			*head_a;
	t_args_list			*head_b;
	t_moves				*moves;
	t_moves				*checker_mvs;
}						t_main;

void					ft_error(char *error, int mod_exit);
int						ft_count_tab(char **tab);
t_main					*ft_get_ptr(void);
int						list_is_sorted(t_args_list *head);
int						ft_abs(int nbr);

int						list_max(t_args_list *list, int skip);
int						list_min(t_args_list *list);
int						list_pos(int value, t_args_list *list);

int						lowest_index_pos(t_main *ptr, char c);
void					position(char c);

void					ft_free_tab(char **tab);
void					ft_free_ptr(void);
void					ft_free_args(t_args_list *head);
void					ft_free_moves(t_moves *head);

t_args_list				*ft_args_listnew(int value);
t_args_list				*ft_args_listlast(t_args_list *lst);
void					ft_args_listadd_back(t_args_list **lst, \
											t_args_list *nw);
int						ft_args_listsize(t_args_list *lst);
int						ft_args_list_pos(t_args_list *lst, int value);

t_moves					*creat_move(char *str);
t_moves					*ft_mvs_listnew(char *move);
t_moves					*ft_mvs_listlast(t_moves *lst);
void					ft_mvs_listadd_back(t_moves **lst, t_moves *nw);
int						ft_mvs_listsize(t_moves *lst);

void					args_list_swap(t_args_list *lst, char c);
void					args_list_push(t_main *ptr, t_args_list *temp, char c);
void					args_list_rrotate(t_args_list *to_rotate, char c);
void					args_list_rotate(t_args_list *to_rotate, char c);

void					ft_r_rotate(char *str);
void					ft_rotate(char *str);
void					ft_push(char *str);
void					ft_swap(char *str);

void					medium_sort(void);
void					short_sort(void);

void					big_sort(void);

void					indexing(t_args_list *lst, int size);

void					move(t_main *ptr);

void					calculate_cost(t_main *ptr);

void					print_moves(t_moves *lst);

void					check_args(int ac, char **av);
void					parsing(int ac, char **av, t_main *ptr);
void					creat_list(char **tab, char *nb, t_main *ptr);
void					check_for_dups(t_main *ptr);

#endif
