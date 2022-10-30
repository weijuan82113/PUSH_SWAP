/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@42studen>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:35:02 by wchen             #+#    #+#             */
/*   Updated: 2022/10/31 02:11:54 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"
# include "ft_printf.h"
# include "push_swap.h"
# include <stdio.h>

bool is_int(char const *num_str)
{
	size_t	i;
	size_t	int_len;

	i = 0;
	if (!*num_str)
		err_exit();
	if (*num_str == '-' || *num_str == '+')
		i ++;
	while ('0' <= num_str[i] && num_str[i] <= '9' && num_str[i])
		i ++;
	int_len = ft_strlen(num_str);
	if (i != int_len)
		return (false);
	else
		return (true);
}

bool is_ints(int argc, char const **argv)
{
	int	i;

	i = 0;
	while (i++ < (argc - 1))
		if (!is_int(argv[i]))
			err_exit();
	return (true);
}

int *is_sorted(int size, char const **argv)
{
	int		i;
	int		*int_arr;

	int_arr = malloc(sizeof(int) * size);
	if(!int_arr)
		err_exit();
	i = 0;
	while (i++ < size)
		int_arr[i - 1] = ft_atoi(argv[i]);
	i = 0;
	while (i < (size - 1))
	{
		if(int_arr[i] > int_arr[i + 1])
			return (int_arr);
		i ++;
	}
	free (int_arr);
	return (NULL);
}

bool is_duplication(int *int_arr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (int_arr[i] == int_arr[i + 1])
			return (true);
		i ++;
	}
	return (false);
}

int *arr_init(int argc,char const **argv)
{
	int	*int_arr;

	if (argc > 1)
		is_ints(argc, argv);
	int_arr = NULL;
	int_arr = is_sorted(argc - 1, argv);
	if (!int_arr)
		return (int_arr);	//print NULL
	merge_sort(int_arr, 0, argc - 2);
	if(is_duplication(int_arr, argc -1))
		err_exit();
	return (int_arr);
}

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

// int	main (int argc,char const **argv)
// {
// 	int *int_arr;

// 	int_arr = arr_init(argc, argv);
// 	print_array(int_arr, argc - 1);
// 	return (0);
// }
