/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@42studen>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 22:57:00 by wchen             #+#    #+#             */
/*   Updated: 2022/11/09 02:02:04 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q push_swap");
// }

// void print_node(t_node *lst)
// {
// 	while (lst)
// 	{
// 		printf("%d-->", lst->content);
// 		lst = lst->next;
// 	}
// 	printf("NULL\n");
// }

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

// static void print_list(t_node *lst)
// {
// 	while (lst)
// 	{
// 		printf("%d-->", *(int *)lst->content);
// 		lst = lst->next;
// 	}
// 	printf("NULL\n");
// }

int	main(int argc,char const **argv)
{
	int		*int_arr;
	t_node	*head;
	t_node	*temp;

	int_arr = arr_init(argc, argv);
	if (!int_arr)
		return (0);
	//print_array(int_arr, argc - 1);
	head = lst_init(argc, argv, int_arr);
	temp = head;
	// printf("----before----\n");
	// print_list(head);
	push_swap(&head, argc);
	// printf("----after----\n");
	// print_list(head);
	//free(temp -> content);
	ft_lstclear(&temp, free);
	return (0);
}
