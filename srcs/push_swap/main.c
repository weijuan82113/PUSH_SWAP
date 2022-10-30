/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@42studen>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 22:57:00 by wchen             #+#    #+#             */
/*   Updated: 2022/10/31 02:20:04 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"
# include "ft_printf.h"
# include "push_swap.h"
# include <stdio.h>

// void print_node(t_node *lst)
// {
// 	while (lst)
// 	{
// 		printf("%d-->", lst->content);
// 		lst = lst->next;
// 	}
// 	printf("NULL\n");
// }

static void	print_array(int *arr, int size)
{
	size_t	i;

	i = 0;
	if(arr)
	{
		while (i < (size_t)(size - 1))
			printf("%d, ", arr[i++]);
		printf("%d \n", arr[i]);
	}
}

void print_list(t_node *lst)
{
	while (lst)
	{
		printf("%d-->", *(int*)lst->content);
		lst = lst->next;
	}
	printf("NULL\n");
}

int	main(int argc,char const **argv)
{
	int		*int_arr;
	t_node	*head;

	int_arr = arr_init(argc, argv);
	if (!int_arr)
		return (0);
	print_array(int_arr, argc - 1);
	head = lst_init(argc, argv, int_arr);
	printf("----lst----\n");
	print_list(head);
	free(head -> content);
	ft_lstclear(&head, free);
	return (0);
}
