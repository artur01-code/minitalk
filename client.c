/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 10:51:43 by jtomala           #+#    #+#             */
/*   Updated: 2022/02/08 15:38:09 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	my_pause(void)
{
	while (g_confirm)
		;
	usleep(300);
	g_confirm = 1;
}

void	handle_client(int sig)
{
	if (sig == SIGUSR1)
		g_confirm = 0;
	else
		printf("Message received\n");
}

void	send_message(int PID, char *str)
{
	unsigned char	mask;
	int				i;

	i = 0;
	while (str[i])
	{
		mask = 0b10000000;
		while (mask)
		{
			if (str[i] & mask)
				kill(PID, SIGUSR1);
			else
				kill(PID, SIGUSR2);
			my_pause();
			mask >>= 1;
		}
		i++;
	}
	i = 0;
	while (i < 8)
	{
		kill(PID, SIGUSR2);
		my_pause();
		i++;
	}
}

//create a PID which is printed out and create the connection.
//while-loop for waiting for action
int	main(int argc, char **argv)
{
	struct sigaction	client;

	if (argc != 3)
	{
		ft_printf("ERROR: Wrong number of arguments\n");
		exit(EXIT_FAILURE);
	}
	client.sa_flags = SA_SIGINFO;
	client.sa_handler = handle_client;
	sigaction(SIGUSR1, &client, NULL);
	sigaction(SIGUSR2, &client, NULL);
	send_message(atoi(argv[1]), argv[2]);
	return (1);
}
