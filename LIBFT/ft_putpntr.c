/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpntr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:07:53 by alvapari          #+#    #+#             */
/*   Updated: 2023/11/22 19:11:04 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(long unsigned int i)
{
	int	cnt_chr;

	cnt_chr = get_hexlen(i);
	if (i >= 16)
	{
		ft_puthex(i / 16);
		ft_puthex(i % 16);
	}
	else
		write(1, &"0123456789abcdef"[i], 1);
	return (cnt_chr);
}

int	ft_putpntr(long unsigned int ad_mem)
{
	int	cnt_chr;

	cnt_chr = 0;
	if (ad_mem == 0)
	{
		write (1, "0x0", 3);
		return (3);
	}
	write (1, "0x", 2);
	cnt_chr = ft_puthex (ad_mem);
	return (cnt_chr + 2);
}
