/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:03:34 by alvapari          #+#    #+#             */
/*   Updated: 2024/04/17 14:41:20 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(char const *str, ...);
int	ft_putchar(char c);
int	get_hexlen(long unsigned int i);
int	ft_puthexl(unsigned int i);
int	ft_putint(int i);
int	ft_puthex(long unsigned int i);
int	ft_putpntr(long unsigned int ad_mem);
int	ft_putstr(char *str);
int	ft_puthexu(unsigned int i);
int	get_ulent(unsigned int num);
int	ft_putui(unsigned int i);
int	get_specifiers(va_list lst, char c);

#endif
