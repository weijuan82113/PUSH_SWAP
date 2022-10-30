/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@42studen>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 19:38:46 by wchen             #+#    #+#             */
/*   Updated: 2022/10/31 01:37:48 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	free_lr(int *l, int *r)
{
	free(l);
	free(r);
}

int	*lr_init(int *int_arr, int n)
{
	int	*ret_int;
	int	i;

	ret_int = malloc(sizeof(int) * n);
	i = 0;
	while (i < n)
	{
		ret_int[i] = int_arr[i];
		i++;
	}
	return (ret_int);
}

void	merge(int *int_arr, int left, int mid, int right)
{
	t_var	var;

	var.n1 = mid - left + 1;
	var.n2 = right - mid;
	var.l_arr = lr_init(&int_arr[left], var.n1);
	var.r_arr = lr_init(&int_arr[mid + 1], var.n2);
	var.i = 0;
	var.j = 0;
	var.k = left;
	while (var.i < var.n1 && var.j < var.n2)
	{
		if (var.l_arr[var.i] <= var.r_arr[var.j])
			int_arr[var.k] = var.l_arr[var.i++];
		else
			int_arr[var.k] = var.r_arr[var.j++];
		var.k++;
	}
	while (var.i < var.n1)
		int_arr[var.k++] = var.l_arr[var.i++];
	while (var.j < var.n2)
		int_arr[var.k++] = var.r_arr[var.j++];
	free_lr(var.l_arr, var.r_arr);
}

void	merge_sort(int *int_arr, int left, int right)
{
	int	mid;

	if (left < right)
	{
		mid = left + (right - left) / 2;
		merge_sort(int_arr, left, mid);
		merge_sort(int_arr, mid + 1, right);
		merge(int_arr, left, mid, right);
	}
}

// static void	print_array(int *arr, int size)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < (size_t)(size - 1))
// 		printf("%d, ", arr[i++]);
// 	printf("%d \n", arr[i]);
// }

// int	main(void)
// {
// 	int	array[] = {12, 23, 42, 13, 43};
// 	int	array_size;

// 	array_size = sizeof(array) / sizeof(array[0]);
// 	printf("the given array is \n");
// 	print_array(array, array_size);
// 	merge_sort(array, 0, array_size - 1);
// 	printf("the output array is \n");
// 	print_array(array, array_size);
// }

// step 1: start

// step 2: declare array and left, right, mid variable

// step 3: perform merge function.
//     if left > right
//         return
//     mid= (left+right)/2
//     mergesort(array, left, mid)
//     mergesort(array, mid+1, right)
//     merge(array, left, mid, right)

// step 4: Stop
