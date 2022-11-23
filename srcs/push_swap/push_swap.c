/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@42studen>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 22:00:25 by wchen             #+#    #+#             */
/*   Updated: 2022/11/23 10:08:12 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void print_list(t_node *lst)
// {
// 	while (lst)
// 	{
// 		printf("%d-->", *(int*)lst->content);
// 		lst = lst->next;
// 	}
// 	printf("NULL\n");
// }

static bool	is_sorted_lst(t_node *head)
{
	int	pre_node;
	int	next_node;

	while (head->next)
	{
		pre_node = *(int *)(head->content);
		next_node = *(int *)(head->next->content);
		if (pre_node > next_node)
			return (false);
		head = head->next;
	}
	return (true);
}

static void	push_min(t_node **head_a, t_node **head_b, int i)
{
	t_var	var;

	var.i = 0;
	while (var.i < i)
	{
		while (*(int *)((*head_a)->content) != var.i && (*head_a)->next != NULL)
			rotate(head_a, "ra");
		push(head_b, head_a, "pb");
		var.i++;
	}
}

static void	three_nums_sort(t_node **head_a)
{
	t_var	var;

	var.i = *(int *)((*head_a)->content);
	var.j = *(int *)((*head_a)->next->content);
	var.k = *(int *)((*head_a)->next->next->content);
	if (var.i > var.j && var.j > var.k)
	{
		rotate(head_a, "ra");
		swap(head_a, "sa");
	}
	else if (var.i > var.k && var.k > var.j)
		rotate(head_a, "ra");
	else if ((var.j < var.i && var.i < var.k) || \
		(var.k < var.i && var.i < var.j))
	{
		if (var.j < var.k)
			swap(head_a, "sa");
		else
			r_rotate(head_a, "rra");
	}
	else
	{
		r_rotate(head_a, "rra");
		swap(head_a, "sa");
	}
}

static void	push_swap_small(t_node **head_a, t_node **head_b, int size)
{
	t_var	var;

	if (size == 2)
		swap(head_a, "sa");
	else
	{
		var.i = 0;
		while (size - var.i > 3)
			var.i++;
		push_min(head_a, head_b, var.i);
		three_nums_sort(head_a);
		while (*head_b != NULL)
			push(head_a, head_b, "pa");
	}
}

void	push_swap(t_node **head_a, int size)
{
	t_node	*head_b;
	t_var	var;

	head_b = NULL;
	var.i = 0;
	if (size <= 5)
		push_swap_small(head_a, &head_b, size);
	else
	{
		while ((size - 1) >> var.i != 0)
		{
			var.j = 0;
			while (!is_sorted_lst(*head_a) && var.j < size)
			{
				if ((*(int *)((*head_a)->content) >> var.i & 1) == 0)
					push(&head_b, head_a, "pb");
				else
					rotate(head_a, "ra");
				var.j++;
			}
			while (head_b != NULL)
				push(head_a, &head_b, "pa");
			var.i++;
		}
	}
}
