/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:23:16 by alvapari          #+#    #+#             */
/*   Updated: 2024/04/17 11:02:40 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void	handlersign(int signal)
{
	static unsigned char	current_char;
	static int				bit_count;

	current_char = current_char | (signal == SIGUSR1);
	bit_count++;
	if (bit_count == 8)
	{
		if (current_char == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", current_char);
		bit_count = 0;
		current_char = 0;
	}
	else
		current_char = current_char << 1;
}

int	main(void)
{
	ft_printf("Welcome! The PID is: %d\n", getpid());
	signal(SIGUSR1, handlersign);
	signal(SIGUSR2, handlersign);
	while (1)
		pause();
	return (0);
}
