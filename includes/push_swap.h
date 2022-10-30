/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@42studen>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 00:57:44 by wchen             #+#    #+#             */
/*   Updated: 2022/10/31 01:37:56 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdbool.h>

typedef struct s_var
{
	int		i,j,k;
	int 	n1;
	int 	n2;
	int		*l_arr;
	int		*r_arr;
}			t_var;

void	err_exit();
void	merge_sort(int *int_array, int left, int right);
int 	*arr_init(int argc,char const **argv);
t_node	*lst_init(int argc, char const **argv, int *int_arr);

#endif
