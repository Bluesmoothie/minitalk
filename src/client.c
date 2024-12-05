/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygille <ygille@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:33:57 by ygille            #+#    #+#             */
/*   Updated: 2024/12/05 16:24:52 by ygille           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

int	main(int argc, char *argv[])
{
	struct sigaction	act;

	if (argc != 3)
	{
		ft_printf("Usage: %s <SERVER_PID> <MESSAGE>\n", argv[0]);
		return (1);
	}
	g_ack = 1;
	act.sa_sigaction = sig_handler;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	ft_printf("Sending : %s to %s\n", argv[2], argv[1]);
	send_sig(ft_atoi(argv[1]), argv[2]);
	ft_printf("Message sent\n");
	return (0);
}

void	send_sig(int pid, char *msg)
{
	int	i;
	int	j;

	i = 0;
	while (msg[i])
	{
		j = 0;
		while (j < 8)
		{
			if (msg[i] & (1 << j))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j++;
			while (g_ack)
				pause();
			g_ack = 1;
		}
		i++;
	}
	j = 0;
	end_of_transmission(pid);
}

void	end_of_transmission(int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		kill(pid, SIGUSR2);
		i++;
		while (g_ack)
			pause();
		g_ack = 1;
	}
}

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (sig == SIGUSR1)
		g_ack = 0;
}
