/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:45:06 by alvapari          #+#    #+#             */
/*   Updated: 2024/04/17 14:39:48 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_intlen(int n)
{
	int	result;

	result = 0;
	if (n < 0)
	{
		n = n * (-1);
		result++;
	}
	if (n == 0)
		result++;
	while (n != 0)
	{
		n = n / 10;
		result++;
	}
	return (result);
}

int	ft_putint(int i)
{
	int	cnt_chr;

	cnt_chr = get_intlen(i);
	if (i == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (i < 0)
	{
		write(1, "-", 1);
		i = i * (-1);
	}
	if (i >= 10)
	{
		ft_putint (i / 10);
		ft_putint (i % 10);
	}
	else
	{
		i = i + '0';
		write (1, &i, 1);
	}
	return (cnt_chr);
}
