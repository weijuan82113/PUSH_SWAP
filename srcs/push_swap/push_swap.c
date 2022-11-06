/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@42studen>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 22:00:25 by wchen             #+#    #+#             */
/*   Updated: 2022/11/06 23:50:40 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	ra(t_node **head_a)
{
	t_node *tail_a;
	t_node *temp_node;

	temp_node = (*head_a) -> next;
	tail_a = ft_lstlast(*head_a);
	tail_a -> next = *head_a;
	(*head_a) -> next = NULL;
	*head_a = temp_node;
	ft_printf("ra\n");
}

void	pa(t_node **head_add, t_node **head_del)
{
	t_node *temp_node;
	if (!(*head_del) -> next)
		temp_node = NULL;
	else
		temp_node = (*head_del) -> next;
	if(*head_add)
		ft_lstadd_front(head_add , *head_del);
	else
		*head_add = ft_lstnew((*head_del) -> content);
	*head_del =  temp_node;
	ft_printf("pa\n");
}

void	pb(t_node **head_add, t_node **head_del)
{
	t_node *temp_node;
	if (!(*head_del) -> next)
		temp_node = NULL;
	else
		temp_node = (*head_del) -> next;
	if(*head_add)
		ft_lstadd_front(head_add , *head_del);
	else
		*head_add = ft_lstnew((*head_del) -> content);
	*head_del =  temp_node;
	ft_printf("pb\n");
}

bool	is_sorted_lst(t_node *head)
{
	int pre_node;
	int next_node;

	while (head -> next)
	{
		pre_node = *(int *)(head -> content);
		next_node = *(int *)(head -> next -> content);
		if(pre_node > next_node)
			return (false);
		head = head -> next;
	}
	return (true);
}

// static void print_list(t_node *lst)
// {
// 	while (lst)
// 	{
// 		printf("%d-->", *(int*)lst->content);
// 		lst = lst->next;
// 	}
// 	printf("NULL\n");
// }

void	push_swap(t_node **head_a, int argc)
{
	t_node	*head_b;
	t_var	var;

	var.i = 0;
	head_b = NULL;
	while((argc-2) >> var.i != 0)
	{
		var.j = 0;
		while(!is_sorted_lst(*head_a) && var.j < argc -1)
		{
			if ((*(int *)((*head_a) -> content) >> var.i & 1) == 0)
				pb(&head_b, head_a);
			else
				ra(head_a);
			// print_list(*head_a);
			// print_list(head_b);
			var.j ++;
		}
		while(head_b != NULL)
			pa(head_a, &head_b);
		var.i ++;
	}
}
