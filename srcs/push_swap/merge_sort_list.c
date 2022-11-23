/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@42studen>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 02:38:59 by wchen             #+#    #+#             */
/*   Updated: 2022/11/23 10:07:14 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	f_b_spt(t_node *source, t_node **f, t_node **b)
{
	t_node	*fast;
	t_node	*slow;

	slow = source;
	fast = source->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			fast = fast->next;
			slow = slow->next;
		}
	}
	*f = source;
	*b = slow->next;
	slow->next = NULL;
}

static t_node	*sorted_merge(t_node *a, t_node *b)
{
	t_node	*result;

	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (*(int *)(a->content) <= *(int *)(b->content))
	{
		result = a;
		result->next = sorted_merge(a->next, b);
	}
	else
	{
		result = b;
		result->next = sorted_merge(a, b->next);
	}
	return (result);
}

void	merge_sort(t_node **headRef)
{
	t_node	*head;
	t_node	*a;
	t_node	*b;

	head = *headRef;
	if ((head == NULL) || (head->next) == NULL)
		return ;
	f_b_spt(head, &a, &b);
	merge_sort(&a);
	merge_sort(&b);
	*headRef = sorted_merge(a, b);
}
// static void	print_list(t_node *lst)
// {
// 	while (lst)
// 	{
// 		printf("%d-->", lst->content);
// 		lst = lst->next;
// 	}
// 	printf("NULL\n");
// }

// int	main(void)
// {
// 	int		arr[] = {1000,1, 1, 42, 13, 43, 503, 223};
// 	int		arr_size;
// 	t_node	*head;

// 	arr_size = sizeof(arr) / sizeof(arr[0]);
// 	head = lst_init(arr, arr_size);
// 	printf("----before_merge_sort----\n");
// 	print_list(head);
// 	merge_sort(&head);
// 	printf("----after_merge_sort----\n");
// 	print_list(head);
// 	ft_lstclear(&head, free);
// }
