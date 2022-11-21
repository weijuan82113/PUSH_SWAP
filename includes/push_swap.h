/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@42studen>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 00:57:44 by wchen             #+#    #+#             */
/*   Updated: 2022/11/21 20:00:01 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "ft_printf.h"
# include <stdbool.h>

typedef struct s_var
{
	int	i;
	int	j;
	int	k;
	int	l;
	int	n1;
	int	n2;
	int	*l_arr;
	int	*r_arr;
}		t_var;

void	err_exit(void);
t_node	*list_init(int argc, char const **argv);
void	merge_sort(t_node **headRef);
void	convert_binary(t_node **input_head, t_node *sorted_head);
void	push_swap(t_node **head_a, int size);
int		ft_atoi_exit(const char *str);
void	rotate(t_node **head, char *state);
void	push(t_node **head_add, t_node **head_del, char *state);
void	swap(t_node **head, char *state);
void	r_rotate(t_node **head, char *state);
void	*free_all(char **chr);

#endif
