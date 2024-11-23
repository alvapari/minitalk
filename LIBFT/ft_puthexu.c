/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:01:13 by alvapari          #+#    #+#             */
/*   Updated: 2023/11/21 21:29:58 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_hexlen(long unsigned int i)
{
	int	cnt;

	cnt = 0;
	if (i == 0)
		return (1);
	while (i != 0)
	{
		i = i / 16;
		cnt++;
	}
	return (cnt);
}

int	ft_puthexu(unsigned int i)
{
	int	cnt_chr;

	cnt_chr = get_hexlen(i);
	if (i >= 16)
	{
		ft_puthexu(i / 16);
		ft_puthexu(i % 16);
	}
	else
		write(1, &"0123456789ABCDEF"[i], 1);
	return (cnt_chr);
}
