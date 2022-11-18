/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@42studen>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:35:02 by wchen             #+#    #+#             */
/*   Updated: 2022/11/18 23:23:21 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_int(char const *num_str)
{
	size_t	i;
	size_t	ope;

	if (!*num_str)
		err_exit();
	i = 0;
	ope = 0;
	while (num_str[i])
	{
		if (num_str[i] == '-' || num_str[i] == '+')
			ope++;
		if ((!ft_isdigit(num_str[i]) && num_str[i] != ' ') || ope > 1)
			return (false);
		while (num_str[i] == ' ')
		{
			i++;
			ope = 0;
		}
		i++;
	}
	return (true);
}

void	init_int_lst(char *str, t_node **int_lst_head)
{
	int	*int_ptr;

	int_ptr = malloc(sizeof(int));
	if (!int_ptr)
		err_exit();
	*int_ptr = ft_atoi_exit(str);
	if (!*int_lst_head)
		*int_lst_head = ft_lstnew(int_ptr);
	else
		ft_lstadd_back(int_lst_head, ft_lstnew(int_ptr));
}

t_node	*is_ints(int argc, char const **argv)
{
	int		i;
	int		j;
	char	**str_arr;
	t_node	*int_lst_head;

	i = 0;
	int_lst_head = NULL;
	while (i++ < argc - 1)
	{
		if (!is_int(argv[i]))
			err_exit();
		str_arr = ft_split(argv[i], ' ');
		j = 0;
		while (str_arr[j])
		{
			init_int_lst(str_arr[j], &int_lst_head);
			j++;
		}
		free_all(str_arr);
	}
	return (int_lst_head);
}

static t_node	*is_sorted(t_node *int_lst_head)
{
	t_node	*temp_head;

	temp_head = int_lst_head;
	while (temp_head->next)
	{
		if (*(int *)(temp_head->content) >= *(int *)(temp_head->next->content))
			return (int_lst_head);
		temp_head = temp_head->next;
	}
	ft_lstclear(&int_lst_head, free);
	return (NULL);
}

t_node	*list_init(int argc, char const **argv)
{
	t_node	*int_lst_head;

	int_lst_head = NULL;
	if (argc > 1)
		int_lst_head = is_ints(argc, argv);
	int_lst_head = is_sorted(int_lst_head);
	if (!int_lst_head)
		return (int_lst_head);
	return (int_lst_head);
}
