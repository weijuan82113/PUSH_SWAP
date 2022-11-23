/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@42studen>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 22:57:00 by wchen             #+#    #+#             */
/*   Updated: 2022/11/23 10:12:51 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q push_swap");
// }

// static void print_list(t_node *lst)
// {
// 	while (lst)
// 	{
// 		printf("%d-->", *((int *)lst->content));
// 		lst = lst->next;
// 	}
// 	printf("NULL\n");
// }

static bool	is_duplication(t_node *head)
{
	while (head -> next)
	{
		if (*(int *)(head -> content) == *(int *)(head -> next -> content))
			return (true);
		head = head -> next;
	}
	return (false);
}

int	main(int argc, char const **argv)
{
	t_node	*input_head;
	t_node	*sorted_head;

	if (argc == 1)
		return (0);
	input_head = list_init(argc, argv);
	if (!input_head)
		return (0);
	sorted_head = list_init(argc, argv);
	merge_sort(&sorted_head);
	if (is_duplication(sorted_head))
		err_exit();
	convert_binary(&input_head, sorted_head);
	push_swap(&input_head, ft_lstsize(input_head));
	ft_lstclear(&input_head, free);
	return (0);
}
