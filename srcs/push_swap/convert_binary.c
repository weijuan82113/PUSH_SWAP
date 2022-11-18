/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_binary.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@42studen>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:38:40 by wchen             #+#    #+#             */
/*   Updated: 2022/11/18 22:36:59 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	convert(t_node **input_head, t_node *sorted_head, int *int_ptr)
{
	while (sorted_head)
	{
		if (*(int *)((*input_head)->content) == *(int *)(sorted_head->content))
		{
			free((*input_head)->content);
			(*input_head)->content = int_ptr;
			break ;
		}
		sorted_head = sorted_head->next;
		*int_ptr = *int_ptr + 1;
	}
}

void	convert_binary(t_node **input_head, t_node *sorted_head)
{
	int		*int_ptr;
	t_node	*ret_head;

	ret_head = *input_head;
	while (*input_head)
	{
		int_ptr = malloc(sizeof(int));
		if (!int_ptr)
			err_exit();
		*int_ptr = 0;
		convert(input_head, sorted_head, int_ptr);
		*input_head = (*input_head)->next;
	}
	*input_head = ret_head;
}
