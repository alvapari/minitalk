/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:02:44 by alvapari          #+#    #+#             */
/*   Updated: 2023/11/22 12:18:42 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexl(unsigned int i)
{
	int	cnt_chr;

	cnt_chr = get_hexlen(i);
	if (i >= 16)
	{
		ft_puthexl(i / 16);
		ft_puthexl(i % 16);
	}
	else
		write(1, &"0123456789abcdef"[i], 1);
	return (cnt_chr);
}
