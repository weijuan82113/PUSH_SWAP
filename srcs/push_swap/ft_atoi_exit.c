/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchen <wchen@42studen>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:11:18 by wchen             #+#    #+#             */
/*   Updated: 2022/11/09 19:11:18 by wchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long long	overflow(int minus_number)
{
	err_exit();
	if (minus_number == 1)
		return (LONG_MIN);
	else
		return (LONG_MAX);
}

static long long	chrtoi(long long num, int minus_number, const char *str)
{
	if (num > INT_MAX / 10 || num < INT_MIN / 10)
		overflow(minus_number);
	if (num == INT_MAX / 10 && (*str - '0') > INT_MAX % 10)
		overflow(minus_number);
	if (num == INT_MIN / 10 && (*str - '0') > INT_MIN % 10 * (-1))
		overflow(minus_number);
	if (minus_number == 1)
		num = num * 10 - (*str - '0');
	else
		num = num * 10 + (*str - '0');
	return (num);
}

int	ft_atoi_exit(const char *str)
{
	int			operator_number;
	int			minus_number;
	long long	num;

	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	operator_number = 0;
	minus_number = 0;
	while (*str == '-' || *str == '+')
	{
		operator_number++;
		if (operator_number > 1)
			return (0);
		if (*str == '-')
			minus_number++;
		str++;
	}
	num = 0;
	while ('0' <= *str && *str <= '9')
	{
		num = chrtoi(num, minus_number, str);
		str++;
	}
	return ((int)num);
}
// #include <stdlib.h>
// #include <stdio.h>
// int main(void)
// {
// 	//   \f\r\n\r\t2147483647
// 	//char str[] = "\f\r\n\r\t-2147483649";
// 	char str[] = "asd";
// 	printf("atoi is %d\n", atoi (str));
// 	printf("ft_atoi is %d\n", ft_atoi (str));
// 	return (0);
// }
