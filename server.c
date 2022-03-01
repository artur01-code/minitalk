/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 10:51:40 by jtomala           #+#    #+#             */
/*   Updated: 2022/02/08 15:35:57 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_server(int sing, siginfo_t *info, void *context)
{
	static unsigned char	c = 0;
	static unsigned char	mask = 0b10000000;

	(void)context;
	if (sing == SIGUSR1)
		c += mask;
	kill(info->si_pid, SIGUSR1);
	mask >>= 1;
	if (!mask)
	{
		write(1, &c, 1);
		mask = 0b10000000;
		if (c == 0)
			kill(info->si_pid, SIGUSR2);
		c = 0;
	}
}

//create a PID which is printed out and create the connection.
//while-loop for waiting for action
int	main(void)
{
	struct sigaction	server;

	ft_printf("Server PID is %d\n", getpid());
	server.sa_flags = SA_SIGINFO;
	server.sa_sigaction = handle_server;
	sigaction(SIGUSR1, &server, NULL);
	sigaction(SIGUSR2, &server, NULL);
	while (1)
	{
		pause();
	}
	return (1);
}
