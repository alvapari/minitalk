/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvapari <alvapari@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:23:40 by alvapari          #+#    #+#             */
/*   Updated: 2024/04/17 11:58:58 by alvapari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include <signal.h>
#include <string.h>

void	send_signal(int pid, unsigned char character)
{
	int				count;
	unsigned char	char_aux;

	count = 8;
	char_aux = character;
	while (count > 0)
	{
		count--;
		char_aux = character >> count;
		if (char_aux % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(42);
	}
}

int	main(int argc, char *argv[])
{
	pid_t		pid;
	const char	*message;
	int			i;

	if (argc != 3)
	{
		ft_printf("Usage: %s <pid> <message>\n", argv[0]);
		exit(0);
	}
	pid = ft_atoi(argv[1]);
	message = argv[2];
	i = 0;
	while (message[i])
	{
		send_signal(pid, message[i]);
		i++;
	}
	send_signal(pid, '\0');
	return (0);
}
