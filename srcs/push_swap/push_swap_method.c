/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_method.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@42studen>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:56:13 by wchen             #+#    #+#             */
/*   Updated: 2022/11/09 19:13:14 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstlast_pre(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next->next != NULL)
		lst = lst->next;
	return (lst);
}

void	r_rotate(t_node **head, char *state)
{
	t_node	*tail;
	t_node	*pre_tail;

	tail = ft_lstlast(*head);
	pre_tail = ft_lstlast_pre(*head);
	pre_tail->next = NULL;
	tail->next = *head;
	*head = tail;
	ft_printf("%s\n", state);
}

void	swap(t_node **head, char *state)
{
	void	*temp_content;

	temp_content = (*head)->content;
	(*head)->content = (*head)->next->content;
	(*head)->next->content = temp_content;
	ft_printf("%s\n", state);
}

void	rotate(t_node **head, char *state)
{
	t_node	*tail;
	t_node	*temp_node;

	temp_node = (*head)->next;
	tail = ft_lstlast(*head);
	tail->next = *head;
	(*head)->next = NULL;
	*head = temp_node;
	ft_printf("%s\n", state);
}

void	push(t_node **head_add, t_node **head_del, char *state)
{
	t_node	*temp_node;

	if (!(*head_del)->next)
		temp_node = NULL;
	else
		temp_node = (*head_del)->next;
	if (*head_add)
		ft_lstadd_front(head_add, *head_del);
	else
		*head_add = ft_lstnew((*head_del)->content);
	*head_del = temp_node;
	ft_printf("%s\n", state);
}
