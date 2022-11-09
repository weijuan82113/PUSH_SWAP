/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@42studen>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:38:40 by wchen             #+#    #+#             */
/*   Updated: 2022/11/09 19:18:40 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	print_array(int *arr, int size)
// {
// 	size_t	i;

// 	i = 0;
// 	if(arr)
// 	{
// 		while (i < (size_t)(size - 1))
// 			printf("%d, ", arr[i++]);
// 		printf("%d \n", arr[i]);
// 	}
// }

int	*covert_to_bit_arr(int argc, char const **argv, int *int_arr)
{
	t_var	var;
	int		*node_contents;

	var.i = 0;
	var.j = 0;
	node_contents = malloc(sizeof(int) * (argc - 1));
	if (!node_contents)
		err_exit();
	while (var.i < argc - 1)
	{
		node_contents[var.i] = ft_atoi_exit(argv[var.i + 1]);
		var.j = 0;
		while (var.j < argc - 1)
		{
			if (node_contents[var.i] == int_arr[var.j])
				node_contents[var.i] = var.j;
			var.j++;
		}
		var.i++;
	}
	return (node_contents);
}

t_node	*lst_init(int argc, char const **argv, int *int_arr)
{
	t_node	*head;
	t_var	var;
	int		*node_contents;

	node_contents = covert_to_bit_arr(argc, argv, int_arr);
	free(int_arr);
	head = ft_lstnew(&node_contents[0]);
	var.i = 1;
	while (var.i < argc - 1)
		ft_lstadd_back(&head, ft_lstnew(&node_contents[var.i++]));
	return (head);
}
